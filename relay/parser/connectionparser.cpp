#include "connectionparser.h"

ConnectionParser::ConnectionParser(Server *server,
                                   QTcpSocket *socket,
                                   PacketSender *sender,
                                   QObject *parent) :
    QObject(parent),
    mServer(server),
    mSocket(socket),
    mPacketSender(sender),
    mInternalSender(new InternalSender(sender, this)) {
}

static QStringList splitRawLine(QString input, bool colonDelimiter) {
    QStringList stringParts;
    if (input.isEmpty()) {
        return stringParts;
    }

    QString colonLessLine = input[0] == QChar(':') ? input.mid(1) : input;
    QString trimmedInput = colonLessLine.trimmed();
    int pos = 0, end;
    while ((end = trimmedInput.indexOf(" ", pos)) >= 0) {
        stringParts.append(trimmedInput.mid(pos, end - pos));
        pos = end + 1;
        if (input[pos + 1] == QChar(':') && colonDelimiter) {
            stringParts.append(trimmedInput.mid(pos + 1));
            return stringParts;
        }
    }
    // No more spaces, add last part of line
    stringParts.append(trimmedInput.mid(pos));
    return stringParts;
}

void ConnectionParser::startParsing() {
    QObject::connect(mSocket, &QTcpSocket::readyRead, this, &ConnectionParser::dataReceived);
    dataReceived();
}

void ConnectionParser::dataReceived() {
    while (mSocket->canReadLine()) {
        QString line = mSocket->readLine();
        QStringList parsedArray = splitRawLine(line, true);
        QString coreCommand = parsedArray.at(0);

        qDebug() << parsedArray;
        if (coreCommand == "PING") {
            mInternalSender->sendPong(parsedArray.at(1));
        } else if (coreCommand == "ERROR") {
            return;
        } else {
            QString command = parsedArray.at(1);

            bool numeric;
            int code = command.toInt(&numeric);
            if (numeric) {
                if (parseCode(parsedArray, code)) {
                    QObject::disconnect(mSocket, &QTcpSocket::readyRead,
                                        this, &ConnectionParser::dataReceived);
                    return;
                }
            } else {
                parseCommand(parsedArray, command);
            }
        }
    }
}

bool ConnectionParser::parseCode(QStringList parsedArray, int code) {
    switch (code) {
        case RPL_WELCOME:
            QString nick = parsedArray.at(2);
            emit connectionStarted(nick);
            return true;
    }
    return false;
}

void ConnectionParser::parseCommand(QStringList parsedArray, QString command) {
    if (command == "NOTICE") {
        QString notice = parsedArray.at(3);
        emit mServer->notice(NoticeEvent(mServer, notice));
    }
}

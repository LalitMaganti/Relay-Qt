#include "serverlineparser.h"

ServerLineParser::ServerLineParser(Server *server, QTcpSocket *socket, PacketSender *sender, QObject *parent) :
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

void ServerLineParser::startParsing() {
    QObject::connect(mSocket, &QTcpSocket::readyRead, this, &ServerLineParser::dataReceived);
    dataReceived();
}

void ServerLineParser::dataReceived() {
    while (mSocket->canReadLine()) {
        QString line = mSocket->readLine();
        QStringList parsedArray = splitRawLine(line, true);
        QString coreCommand = parsedArray.at(0);

        qDebug() << "LineParser: " << parsedArray;
        if (coreCommand == "PING") {

        } else if (coreCommand == "ERROR") {

        } else {
        }
    }
}

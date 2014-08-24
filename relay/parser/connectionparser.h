#ifndef CONNECTIONPARSER_H
#define CONNECTIONPARSER_H

#include <QObject>
#include <QString>
#include <QStringList>

class Server;

#include "ircconstants.h"
#include "server.h"
#include "sender/internalsender.h"
#include "sender/packetsender.h"

class ConnectionParser : public QObject {
    Q_OBJECT

    public:
        explicit ConnectionParser(Server *server,
                                  QTcpSocket *socket,
                                  PacketSender *sender,
                                  QObject *parent = 0);

        void startParsing();

    private:
        Server *mServer;
        QTcpSocket *mSocket;
        PacketSender *mPacketSender;
        InternalSender *mInternalSender;

        bool parseCode(QStringList parsedArray, int code);
        void parseCommand(QStringList parsedArray, QString command);

    signals:
        void connectionStarted(QString nick);

    private slots:
        void dataReceived();
};

#endif // CONNECTIONPARSER_H

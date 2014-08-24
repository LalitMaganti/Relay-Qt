#ifndef SERVERLINEPARSER_H
#define SERVERLINEPARSER_H

#include <QObject>
#include <QTcpSocket>

#include "server.h"
#include "sender/packetsender.h"

class ServerLineParser : public QObject
{
    Q_OBJECT
    public:
        explicit ServerLineParser(Server *server,
                                  QTcpSocket *socket,
                                  PacketSender *packetSender,
                                  QObject *parent = 0);

        void startParsing();

    private:
        Server *mServer;
        QTcpSocket *mSocket;
        PacketSender *mPacketSender;

    private slots:
        void dataReceived();
};

#endif // SERVERLINEPARSER_H

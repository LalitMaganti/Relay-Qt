#ifndef IRCCONNECTION_H
#define IRCCONNECTION_H

#include <QTcpSocket>

class ConnectionParser;
class IRCConnection;

#include "server.h"
#include "serverconfiguration.h"
#include "parser/connectionparser.h"
#include "parser/serverlineparser.h"
#include "sender/packetsender.h"

class IRCConnection : public QObject
{
    Q_OBJECT

    public:
        IRCConnection(ServerConfiguration* configuration);

        void startConnection();

    private:
        ServerConfiguration *mConfiguration = NULL;
        Server *mServer = NULL;
        QTcpSocket *mSocket = NULL;
        PacketSender *mPacketSender = NULL;
        ServerLineParser *mServerLineParser = NULL;
        ConnectionParser *mConnectionParser = NULL;

        void connect();

    private slots:
        void socketConnected();
        void connected(QString nick);
};

#endif // IRCCONNECTION_H

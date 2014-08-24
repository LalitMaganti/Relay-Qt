#include <QDebug>

#include "ircconnection.h"

#include "packet/internal/userpacket.h"
#include "packet/server/nickpacket.h"
#include "sender/packetsender.h"

IRCConnection::IRCConnection(ServerConfiguration *configuration) :
    mConfiguration(configuration),
    mServer(new Server(configuration, this)),
    mPacketSender(new PacketSender(this)) {
}

void IRCConnection::startConnection() {
    connect();
}

void IRCConnection::connect() {
    delete mSocket;
    delete mConnectionParser;

    mSocket = new QTcpSocket(this);
    mSocket->connectToHost(mConfiguration->hostName(), mConfiguration->port());

    mPacketSender->onSocketCreated(mSocket);

    mConnectionParser = new ConnectionParser(mServer, mSocket, mPacketSender, this);
    QObject::connect(mConnectionParser, &ConnectionParser::connectionStarted, this, &IRCConnection::connected);
    QObject::connect(mSocket, &QTcpSocket::connected, this, &IRCConnection::socketConnected);
}

void IRCConnection::socketConnected() {
    UserPacket userPacket("tilal", "lalit");
    mPacketSender->sendPacket(&userPacket);

    NickPacket nickPacket("tilal699|testing");
    mPacketSender->sendPacket(&nickPacket);

    mConnectionParser->startParsing();
}

void IRCConnection::connected(QString nick) {
    mServerLineParser = new ServerLineParser(mServer, mSocket, mPacketSender, this);
    mServerLineParser->startParsing();
}

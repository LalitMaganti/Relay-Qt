#include "server.h"

Server::Server(ServerConfiguration *configuration, IRCConnection *connection) :
    QObject(connection),
    mConfiguration(configuration),
    mConnection(connection),
    mBuffer(new QList<ServerEvent>()) {
    QObject::connect(this, &Server::notice, this, &Server::onEvent);
}

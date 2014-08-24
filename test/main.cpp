#include <QDebug>
#include <QCoreApplication>
#include <QTcpSocket>

#include "ircconnection.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    ServerConfiguration::Builder builder;
    builder.setHostName("irc.freenode.net");
    builder.setPort(6667);

    ServerConfiguration configuration(&builder);
    IRCConnection connection(&configuration);
    connection.startConnection();

    return a.exec();
}

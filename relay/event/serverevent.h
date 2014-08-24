#ifndef SERVEREVENT_H
#define SERVEREVENT_H

class Server;

#include "server.h"
#include "event/event.h"

class ServerEvent : public Event {
    public:
        Server *server;

        ServerEvent(Server *server) :
            Event(),
            server(server) {
        }
};

class NoticeEvent : public ServerEvent {
    public:
        QString notice;

        NoticeEvent(Server* server, QString notice) :
            ServerEvent(server),
            notice(notice) {
        }
};
#endif // SERVEREVENT_H

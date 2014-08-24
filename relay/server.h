#ifndef SERVER_H
#define SERVER_H

#include <QObject>

#include "ircconnection.h"
#include "serverconfiguration.h"
#include "event/serverevent.h"

class Server : public QObject {
    Q_OBJECT

    public:
        explicit Server(ServerConfiguration *configuration,
                        IRCConnection *connection);

    signals:
        void notice(NoticeEvent event);

    private:
        ServerConfiguration *mConfiguration = NULL;
        IRCConnection *mConnection = NULL;
        QList<ServerEvent> *mBuffer = NULL;

    private slots:
        void onEvent(ServerEvent event) {
            mBuffer->append(event);
        }
};
#endif // SERVER_H

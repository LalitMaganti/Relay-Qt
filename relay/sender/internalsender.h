#ifndef INTERNALSENDER_H
#define INTERNALSENDER_H

#include <QObject>

#include "sender/packetsender.h"

class InternalSender : public QObject {
    Q_OBJECT

    public:
        explicit InternalSender(PacketSender *sender,
                                QObject *parent = 0);

    private:
        PacketSender mPacketSender;

        void sendPong(QString source);
};

#endif // INTERNALSENDER_H

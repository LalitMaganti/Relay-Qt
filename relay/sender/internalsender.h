#ifndef INTERNALSENDER_H
#define INTERNALSENDER_H

#include <QObject>

#include "sender/packetsender.h"

class InternalSender : public QObject {
    Q_OBJECT

    public:
        explicit InternalSender(PacketSender *sender,
                                QObject *parent = 0);

        void sendPong(QString source);

    private:
        PacketSender *mPacketSender;
};

#endif // INTERNALSENDER_H

#ifndef NICKPACKET_H
#define NICKPACKET_H

#include <QObject>

#include "packet/packet.h"

class NickPacket : public Packet {
    Q_OBJECT

    public:
        explicit NickPacket(QString nick) :
            mNick(nick) {
        }

        QString lineToSend() {
            return QString("NICK %1").arg(mNick);
        }

    private:
        QString mNick;
};

#endif // NICKPACKET_H

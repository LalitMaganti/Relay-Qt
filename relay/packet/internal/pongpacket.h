#ifndef PONGPACKET_H
#define PONGPACKET_H

#include <QString>

class PongPacket : public Packet {
    public:
        PongPacket(QString source) :
            mSource(source) {
        }

        QString lineToSend() {
            return QString("PONG %1").arg(mSource);
        }

    private:
        QString mSource;
};

#endif // PONGPACKET_H

#ifndef PACKET_H
#define PACKET_H

#include <QString>

class Packet {
    public:
        explicit Packet() {
        }
        virtual QString lineToSend() = 0;
};

#endif // PACKET_H

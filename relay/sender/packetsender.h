#ifndef PACKETSENDER_H
#define PACKETSENDER_H

#include "packet/packet.h"

#include <QObject>
#include <QTcpSocket>

class PacketSender : public QObject
{
    Q_OBJECT

    public:
        explicit PacketSender(QObject *parent);

        void sendPacket(Packet *packet);
        void onSocketCreated(QTcpSocket *socket);

    private:
        QTcpSocket *mSocket;
};

#endif // PACKETSENDER_H

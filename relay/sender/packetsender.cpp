#include "packetsender.h"

PacketSender::PacketSender(QObject *parent) :
    QObject(parent) {
}

void PacketSender::sendPacket(Packet *packet) {
    QString data = packet->lineToSend() + "\r\n";
    mSocket->write(data.toUtf8());
}

void PacketSender::onSocketCreated(QTcpSocket *socket) {
    mSocket = socket;
}

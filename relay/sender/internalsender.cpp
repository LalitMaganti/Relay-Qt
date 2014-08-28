#include "internalsender.h"

#include "packet/internal/pongpacket.h"

InternalSender::InternalSender(PacketSender *sender, QObject *parent) :
    QObject(parent),
    mPacketSender(sender){
}

void InternalSender::sendPong(QString source) {
    PongPacket packet(source);
    mPacketSender->sendPacket(&packet);
}

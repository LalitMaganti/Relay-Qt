#include "internalsender.h"

InternalSender::InternalSender(PacketSender *sender, QObject *parent) :
    QObject(parent),
    mPacketSender(sender){
}

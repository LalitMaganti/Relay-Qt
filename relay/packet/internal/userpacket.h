#ifndef USERPACKET_H
#define USERPACKET_H

#include <QObject>

#include "packet/packet.h"

class UserPacket : public Packet {
    Q_OBJECT

    public:
        explicit UserPacket(QString userName, QString realName) :
            mUserName(userName),
            mRealName(realName) {
        }

        QString lineToSend() {
            return QString("USER %1 8 * :%2").arg(mUserName, mRealName);
        }

    private:
        QString mUserName;
        QString mRealName;
};

#endif // USERPACKET_H

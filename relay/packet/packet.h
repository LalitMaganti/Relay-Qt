#ifndef PACKET_H
#define PACKET_H

#include <QObject>
#include <QString>

class Packet : public QObject {
    Q_OBJECT
public:
    explicit Packet(QObject *parent = 0) : QObject(parent) {
    }
    virtual QString lineToSend() = 0;
};

#endif // PACKET_H

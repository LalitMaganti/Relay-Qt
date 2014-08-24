#ifndef EVENT_H
#define EVENT_H

#include <QDateTime>
#include <QObject>

class Event {

    public:
        uint timestamp;

        Event() {
            timestamp = QDateTime::currentDateTime().toTime_t();
        }
};

#endif // EVENT_H

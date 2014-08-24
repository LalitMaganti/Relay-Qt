#ifndef SERVERCONFIGURATION_H
#define SERVERCONFIGURATION_H

#include <QObject>
#include <QString>

class ServerConfiguration : public QObject {
    Q_OBJECT

    public:
        class Builder {
            public:
                QString hostName() const {
                    return mHostName;
                }

                int port() const {
                    return mPort;
                }

                void setHostName(const QString &hostName) {
                    mHostName = hostName;
                }

                void setPort(int port) {
                    mPort = port;
                }

            private:
                QString mHostName;
                int mPort;
        };

        ServerConfiguration(Builder* builder) :
            mHostName(builder->hostName()),
            mPort(builder->port()) {
        }

        QString hostName() const {
            return mHostName;
        }

        int port() const {
            return mPort;
        }

private:
        const QString mHostName;
        const int mPort;
};

#endif // SERVERCONFIGURATION_H

QT       += network
QT       -= gui

CONFIG   += c++11
CONFIG   += lib

TARGET    = relay
TEMPLATE  = lib

DEFINES  += RELAYQT_LIBRARY

SOURCES  += ircconnection.cpp \
    parser/connectionparser.cpp \
    sender/packetsender.cpp \
    sender/internalsender.cpp \
    server.cpp \
    parser/serverlineparser.cpp

HEADERS  += ircconnection.h\
            serverconfiguration.h \
    parser/connectionparser.h \
    sender/packetsender.h \
    packet/packet.h \
    packet/internal/userpacket.h \
    packet/server/nickpacket.h \
    sender/internalsender.h \
    ircconstants.h \
    server.h \
    event/event.h \
    event/serverevent.h \
    parser/serverlineparser.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

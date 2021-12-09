QT += core gui sql widgets

TEMPLATE = lib
TARGET = Communication


include(../../common.pri)

DEFINES += COMMON_LIBRARY

INCLUDEPATH += $$SHARE_PATH/Communication

HEADERS += \
        $$SHARE_PATH/Communication/Communication.h

SOURCES += \
    Communication.cpp

DESTDIR = $$DEST_LIBS


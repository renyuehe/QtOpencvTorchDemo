QT += gui widgets

#TARGET = FilterPlugin
TEMPLATE = lib
DEFINES += FILTERPLUGIN_LIBRARY

CONFIG += c++11

DEFINES += QT_DEPRECATED_WARNINGS

include($${PWD}/../comPlugin.pri)
include($${PWD}/../../thirdLib/thirdLib.pri)
include($${PWD}/../../refer/refer.pri)

SOURCES += \
    FilterForm.cpp \
        FilterPlugin.cpp \


HEADERS += \
    FilterForm.h \
        FilterPlugin.h \
        filterplugin_global.h \
        $$SHARE_PATH/CommonHeader/ComPluginInterface.h \

unix {
    target.path = /usr/lib
    INSTALLS += target
}

FORMS += \
    FilterForm.ui

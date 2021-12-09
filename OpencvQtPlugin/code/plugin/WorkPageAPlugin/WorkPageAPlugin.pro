QT  +=  gui  core  widgets

TEMPLATE = lib
DEFINES += WORKPAGEAPLUGIN_LIBRARY

CONFIG += c++11

include($${PWD}/../comPlugin.pri)

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    workpageaplugin.cpp

HEADERS += \
    WorkPageAPlugin_global.h \
    workpageaplugin.h \
    $$SHARE_PATH/CommonHeader/ComPluginInterface.h \

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    test1.json

include(../top.pri)

INCLUDEPATH += $$PWD


LIBS += -L$$DEST_LIBS
#LIBS += $$DEST_LIBS/components.lib
LIBS += -lcomponents

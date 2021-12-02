#BINARY_RESULT_DIR = $${TOP_BUILD_DIR}

isEmpty(BINARY_RESULT_DIR) {
    BINARY_RESULT_DIR = $${PWD}
}

#QMAKE_CXXFLAGS +=  -Wno-unused-parameter
#QMAKE_CXXFLAGS += -Wno-unused-variable
#message(TOP_BUILD_DIR: $$TOP_BUILD_DIR)


CONFIG(release, debug|release){
#    message(Release)
    BUILD_TYPE = release
}else{
#    message(Debug)
    BUILD_TYPE = debug
}

#BUILD_DIR = $${BINARY_RESULT_DIR}/build/$${QT_VERSION}


#unix{
#    ARCH_DIR       = $${OUT_PWD}/unix
#    ARCH_TYPE      = unix
#    macx{
#        ARCH_DIR       = $${OUT_PWD}/macx
#        ARCH_TYPE      = macx
#    }
#    linux{
#        !contains(QT_ARCH, x86_64){
##            message("Compiling for 32bit system")
#            ARCH_DIR       = $${OUT_PWD}/linux32
#            ARCH_TYPE      = linux32
#        }else{
##            message("Compiling for 64bit system")
#            ARCH_DIR       = $${OUT_PWD}/linux64
#            ARCH_TYPE      = linux64
#        }
#    }
#}

#win32 {
#    !contains(QT_ARCH, x86_64) {
##        message("Compiling for 32bit system")
#        ARCH_DIR       = $${OUT_PWD}/win32
#        ARCH_TYPE      = win32
#    } else {
##        message("Compiling for 64bit system")
#        ARCH_DIR       = $${OUT_PWD}/win64
#        ARCH_TYPE      = win64
#    }
#}

#QMAKE_CXXFLAGS +=  -Wno-unused-parameter
#QMAKE_CXXFLAGS += -Wno-unused-variable
#DEST_LIBS = $${BUILD_DIR}/$${ARCH_TYPE}/$${BUILD_TYPE}/lib
#DEST_BINS = $${BUILD_DIR}/$${ARCH_TYPE}/$${BUILD_TYPE}/$${TARGET}

LIBS_PATH  = $$PWD/Exe
SHARE_PATH = $$PWD/ShareCode
DEST_LIBS  = $$PWD/../Exe
DEST_BINS  = $$PWD/../Exe
DEST_PLUGIN = $$PWD/../Exe/plugin


MOC_DIR        = $${ARCH_DIR}/$${BUILD_TYPE}/moc
UI_DIR         = $${ARCH_DIR}/$${BUILD_TYPE}/ui
UI_HEADERS_DIR = $${ARCH_DIR}/$${BUILD_TYPE}/ui
UI_SOURCES_DIR = $${ARCH_DIR}/$${BUILD_TYPE}/ui
OBJECTS_DIR    = $${ARCH_DIR}/$${BUILD_TYPE}/obj
RCC_DIR        = $${ARCH_DIR}/$${BUILD_TYPE}/rcc

INDEXANALY_VERSION_MAJOR = 1
INDEXANALY_VERSION_MINOR = 0
INDEXANALY_VERSION_RELEASE = 0

INDEXANALY_VERSION = '$${INDEXANALY_VERSION_MAJOR}.$${INDEXANALY_VERSION_MINOR}.$${INDEXANALY_VERSION_RELEASE}'
DEFINES *= INDEXANALY_VERSION_STR=\\\"$${INDEXANALY_VERSION}\\\"


#PUGIXML_PATH = $$PWD/pugixml




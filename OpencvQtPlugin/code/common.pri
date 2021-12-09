

#如果二进制文件是空,则为当前文件夹
isEmpty(BINARY_RESULT_DIR) {
    BINARY_RESULT_DIR = $${PWD}
}


#根据Qt中项目配置类型,release或者是debug修改 BUILD_TYPE 类型
CONFIG(release, debug|release){
    BUILD_TYPE = release
}else{
    BUILD_TYPE = debug
}


#
BUILD_DIR = $${BINARY_RESULT_DIR}/build/$${QT_VERSION}


unix{
    ARCH_DIR       = $${OUT_PWD}/unix
    ARCH_TYPE      = unix
    macx{
        ARCH_DIR       = $${OUT_PWD}/macx
        ARCH_TYPE      = macx
    }
    linux{
        !contains(QT_ARCH, x86_64){
#            message("Compiling for 32bit system")
            ARCH_DIR       = $${OUT_PWD}/linux32
            ARCH_TYPE      = linux32
        }else{
#            message("Compiling for 64bit system")
            ARCH_DIR       = $${OUT_PWD}/linux64
            ARCH_TYPE      = linux64
        }
    }
}
#message("ARCH_DIR = "$${ARCH_DIR})
#message("ARCH_TYPE = "$${ARCH_TYPE})
#message("ARCH_DIR = "$${ARCH_DIR})


win32 {
    !contains(QT_ARCH, x86_64) {
#        message("Compiling for 32bit system")
        ARCH_DIR       = $${OUT_PWD}/win32
        ARCH_TYPE      = win32
    } else {
#        message("Compiling for 64bit system")
        ARCH_DIR       = $${OUT_PWD}/win64
        ARCH_TYPE      = win64
    }
}

#QMAKE_CXXFLAGS +=  -Wno-unused-parameter
#QMAKE_CXXFLAGS += -Wno-unused-variable
#DEST_LIBS = $${BUILD_DIR}/$${ARCH_TYPE}/$${BUILD_TYPE}/lib
#DEST_BINS = $${BUILD_DIR}/$${ARCH_TYPE}/$${BUILD_TYPE}/$${TARGET}


LIBS_PATH  = $$PWD/Exe                  #？？？？用不上
SHARE_PATH = $$PWD/ShareCode            #共享文件
DEST_LIBS  = $$PWD/../Exe               #静态库
DEST_BINS  = $$PWD/../Exe               #动态库
DEST_PLUGIN = $$PWD/../Exe/plugin       #插件
QTITANDIR  = $$PWD/lib/QtitanRibbon/src #QTITAN第三方界面库，用不上

message("PWD = "$${PWD})
message("LIBS_PATH = "$${LIBS_PATH})
message("SHARE_PATH = "$${SHARE_PATH})
message("DEST_LIBS = "$${DEST_LIBS})
message("DEST_BINS = "$${DEST_BINS})
message("DEST_PLUGIN = "$${DEST_PLUGIN})
message("QTITANDIR = "$${QTITANDIR})


#中间文件MOC 和 界面文件UI 和 目标文件OBJ 和 资源文件RCC 等QT的系统文件
MOC_DIR        = $${ARCH_DIR}/$${BUILD_TYPE}/moc
UI_DIR         = $${ARCH_DIR}/$${BUILD_TYPE}/ui
UI_HEADERS_DIR = $${ARCH_DIR}/$${BUILD_TYPE}/ui
UI_SOURCES_DIR = $${ARCH_DIR}/$${BUILD_TYPE}/ui
OBJECTS_DIR    = $${ARCH_DIR}/$${BUILD_TYPE}/obj
RCC_DIR        = $${ARCH_DIR}/$${BUILD_TYPE}/rcc


INDEXANALY_VERSION_MAJOR = 1 #主版本号
INDEXANALY_VERSION_MINOR = 0 #次版本号
INDEXANALY_VERSION_RELEASE = 0 #发行版本号

#主版本号+次版本号+发行版本号
INDEXANALY_VERSION = '$${INDEXANALY_VERSION_MAJOR}.$${INDEXANALY_VERSION_MINOR}.$${INDEXANALY_VERSION_RELEASE}'
#message("INDEXANALY_VERSION = "$${INDEXANALY_VERSION})

#宏定义:表示在代码中可以打印这个变量 qDebug() <<  INDEXANALY_VERSION_STR;
DEFINES *= INDEXANALY_VERSION_STR=\\\"$${INDEXANALY_VERSION}\\\"



#PUGIXML_PATH = $$PWD/pugixml

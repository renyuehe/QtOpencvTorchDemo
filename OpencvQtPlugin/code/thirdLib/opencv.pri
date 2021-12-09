################################ opencv ################################
INCLUDEPATH += \
    D:\lib\opencv_454\build\include\opencv2\
    D:\lib\opencv_454\build\include\opencv\
    D:\lib\opencv_454\build\include

CONFIG(debug,debug|release){
LIBS += D:\lib\opencv_454\build\x64\vc15\lib\opencv_world454d.lib
}
else{
LIBS += D:\lib\opencv_454\build\x64\vc15\lib\opencv_world454.lib
}


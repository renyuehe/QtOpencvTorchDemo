################################ opencv ################################
INCLUDEPATH += \
    D:\lib\opencv_454\build\include\opencv2\
#    D:\lib\opencv\build\include\opencv\
    D:\lib\opencv_454\build\include

CONFIG(debug,debug|release){
LIBS += D:\lib\opencv_454\build\x64\vc15\lib\opencv_world454d.lib
}
else{
LIBS += D:\lib\opencv_454\build\x64\vc15\lib\opencv_world454.lib
}

################################ libtorch ################################

INCLUDEPATH+=D:\lib\libtorch-win-shared-with-deps-1.9.0+cpu\libtorch\include
INCLUDEPATH+=D:\lib\libtorch-win-shared-with-deps-1.9.0+cpu\libtorch\include\torch\csrc\api\include

CONFIG(debug,debug|release){
    LIBS += -LD:\lib\libtorch-win-shared-with-deps-debug-1.9.0+cpu\libtorch\lib \
    -lasmjit \
    -lc10 \
    -lcaffe2_module_test_dynamic \
    -lfbjni \
    -ltorch \
    -ltorch_cpu \
    -lclog -lcpuinfo\
    -ldnnl -lfbgemm\
    -lmkldnn\
#-lcaffe2_detectron_ops \
#-lCaffe2_perfkernels_avx \
#-lCaffe2_perfkernels_avx2 \
#-lCaffe2_perfkernels_avx512 \
#-lkineto \
#-lmkldnn \
#-lpthreadpool \
#-lpytorch_jni \
#-lXNNPACK \
#####这几个lib开头的lib无法打开，也不知道为什么#############################
#-llibprotobufd \
#-llibprotobuf-lited \
#-llibprotocd \
}
else{
    LIBS += -LD:\lib\libtorch-win-shared-with-deps-1.9.0+cpu\libtorch\lib \
    -lc10 \
    -lasmjit \
    -lcaffe2_module_test_dynamic \
    -ltorch \
    -ltorch_cpu \
    -lclog -lcpuinfo\
    -ldnnl -lfbgemm\
    -lmkldnn \
    -lfbjni \
#-lcaffe2_detectron_ops \
#-lCaffe2_perfkernels_avx \
#-lCaffe2_perfkernels_avx2 \
#-lCaffe2_perfkernels_avx512 \
#-lkineto \
#-lmkldnn \
#-lpthreadpool \
#-lpytorch_jni \
#-lXNNPACK \
#####这几个lib开头的lib无法打开，也不知道为什么#############################
#-llibprotobufd \
#-llibprotobuf-lited \
#-llibprotocd \
}

################################ other ################################

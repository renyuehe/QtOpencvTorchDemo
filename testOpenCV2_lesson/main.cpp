//#include "widget.h"

#include <QApplication>
#include "OpencvOper.h"
#include "Cv2Qt.h"
#include <QImage>
#include <QWidget>
#include <QPixmap>
#include <QHBoxLayout>
#include <QLabel>

void testOpercvOper();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    {
        /**测试 OpencvOper 的模块**/
        testOpercvOper();
    }


    return a.exec();
}

void testOpercvOper(){
        OpencvOper::openImgOper();
//        OpencvOper::openImgOper2();

    //    OpencvOper::channelSplite();
    //    OpencvOper::VideoCaptureOper();
    //    OpencvOper::cvtColorOper();
    //    OpencvOper::drawShapeOper();

    //    OpencvOper::thresholdOper();
    //    OpencvOper::adapterThresholdOper();
    //    OpencvOper::imgMathOperation();
    //    OpencvOper::imgMathOperation2();
    //    OpencvOper::imgBitOperation();

    //    OpencvOper::transposeFlipOper();
    //    OpencvOper::warpAffine();
    //    OpencvOper::warpPerspective();
    //    OpencvOper::morphologicalOper();
    //    OpencvOper::graphFilterOper();

    //    OpencvOper::CannyOper();
    //    OpencvOper::findContours();
    //    OpencvOper::approxPolyDPOper();
//        OpencvOper::convexOper();
    //    OpencvOper::boundaryDetection();

    //    OpencvOper::contoursProperty();
    //    OpencvOper::huofuOper();
    //    OpencvOper::hintDetact();
}






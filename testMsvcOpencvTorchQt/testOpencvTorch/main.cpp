#include "widget.h"
#include <QApplication>

#include <QFileDialog>
#include <QLabel>

#include "Cv2Qt.h"
#include "OpencvOper.h"
#include "OpencvOper2.h"
#include "TorchOperBase.h"
#include "TorchOper.h"
#include "TorchOper2.h"


void testCv2Qt();

void testOpercvOper();
void testOpercvOper2();

void testTorchOperBase();
void testTorchOper();
void testTorchOper2();



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    /**主界面**/
    Widget widget;
    widget.show();



    /**测试 OpencvOper 的模块**/
//    testOpercvOper();

    /**测试 OpencvOper2 的模块**/
//    testOpercvOper2();

    /**测试 Cv2Qt 模块**/
//    testCv2Qt();

    /**测试 TorchOperBase 模块**/
//    testTorchOperBase();

    /**测试 TorchOper 模块**/
//    testTorchOper();

    /**测试 TorchOper2 模块**/
//    testTorchOper2();


    return a.exec();
}

void testOpercvOper2(){
    OpencvOper2::fun_07();
}

void testOpercvOper(){
//    OpencvOper::VideoCaptureOper();
}

void testTorchOperBase(){
    TorchOperBase::testATen();
}

void testTorchOper(){
    TorchOper::jitModulePredictNumber();
    //    TorchOper::jitPredictYellowArea();
}

void testTorchOper2(){
    TorchOper2::testVGG16();
}

void testCv2Qt(){
    QString fileName = QFileDialog::getOpenFileName(nullptr,
                                                    ("文件对话框！"),
                                                    "F:",
                                                    ("图片文件(*png *jpg);;"));

    cv::Mat mat=cv::imread(fileName.toStdString(),1);//一定要使用绝对路径，其他可以回报错

    QLabel * lable = Cv2Qt::cvMat_to_QLabel(mat);

    lable->show();
    QImage qimage = Cv2Qt::cvMat_to_QImage(mat);

    cv::Mat mat2 = Cv2Qt::QImage_to_cvMat(qimage, true);

    cv::imshow("mat2", mat2);
}


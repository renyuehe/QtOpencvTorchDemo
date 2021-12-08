//torch
//#include "torch/script.h"
//#include "torch/torch.h"
#include "opencv2/opencv.hpp"
//cv
#include <QApplication>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

//
#include "widget.h"

#include <iostream>
using namespace std;

#include <QDebug>
#define DBG (qDebug()<<__LINE__<<"--------------------------")


#include <QFileDialog>
#include <QDebug>

//#include <OpencvOper.h>
cv::Mat getGaussianKernel( int n, double sigma, int ktype );


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    DBG;
//    OpencvOper::openImgOper();
    QString fileName = QFileDialog::getOpenFileName(nullptr,
                                                    ("文件对话框！"),
                                                    "F:",
                                                    ("图片文件(*png *jpg);;"));

    cv::Mat image=cv::imread(fileName.toStdString());//一定要使用绝对路径，其他可以回报错

//    cv::namedWindow( "Displaywindow");
//    cv::imshow( "Displaywindow", image);

    DBG;

    return a.exec();
}


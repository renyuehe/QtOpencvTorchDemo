//torch
#include "torch/script.h"
#include "torch/torch.h"
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
cv::Mat getGaussianKernel( int n, double sigma, int ktype );


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    DBG;

    DBG;

    return a.exec();
}


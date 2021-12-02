#include "widget.h"

#include <QApplication>
#include <QFileDialog>
#include <vector>
#include <QDebug>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QString fileName = QFileDialog::getOpenFileName(nullptr,
                                                    ("文件对话框！"),
                                                    "F:",
                                                    ("图片文件(*png *jpg);;"));

    cv::Mat image=cv::imread(fileName.toStdString(),1);//一定要使用绝对路径，其他可以回报错

    cv::namedWindow( "Display window", cv::WINDOW_AUTOSIZE );
    cv::imshow( "Display window", image );

    Widget w;
    w.show();
    return a.exec();
}

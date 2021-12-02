//#include "widget.h"

#include <QApplication>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;

#include <QFileDialog>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString fileName = QFileDialog::getOpenFileName(nullptr,
                                                    ("文件对话框！"),
                                                    "F:",
                                                    ("图片文件(*png *jpg);;"
                                                       "本本文件(*txt)"));

    qDebug() << fileName;
    Mat image=imread(fileName.toStdString(),1);//一定要使用绝对路径，其他可以回报错

    namedWindow( "Display window", WINDOW_AUTOSIZE );
    imshow( "Display window", image );

    return a.exec();
}

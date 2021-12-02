#include "widget.h"
#include "ui_widget.h"
#include "Cv2Qt.h"
#include <QFileDialog>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QString filename = "D:\\Desktop\\small_girl.jpg";
    cv::Mat img = cv::imread(filename.toStdString());
//    cv::namedWindow(filename.toStdString(), CV_WINDOW_AUTOSIZE);
//    Cv2Qt::namedWindowToWidget(filename.toStdString(), ui->label);

//    cv::imshow(filename.toStdString(), img);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_3_clicked()
{
     Cv2Qt::VideoCaptureToWidget("D:\\Desktop\\StartMenu_Win8.mp4", ui->label);
}

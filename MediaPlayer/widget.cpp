#include "widget.h"
#include "ui_widget.h"

#include <QFileDialog>
#include <QHBoxLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);


}

Widget::~Widget()
{
    delete ui;
}

void Widget::videoPlayer()
{

    QString filePathName = QFileDialog::getOpenFileName(nullptr,
                                                    ("文件对话框！"),
                                                    "F:",
                                                    ("视频文件(*.wmv);;"));


    player = new QMediaPlayer(this);


    QHBoxLayout * hlayouot = new QHBoxLayout(this);
    videoWidget = new QVideoWidget(this);
    hlayouot->addWidget(videoWidget);


    videoWidget->resize(600,300);           //设置视频输出窗口大小


    player->setVideoOutput(videoWidget);    //设置视频由videoWidget对象执行

    player->setMedia(QUrl::fromLocalFile(filePathName));    //设置视频本地路径

//    videoWidget->show();
    player->play();                         //播放视频
}

void Widget::mediaPlayer()
{

    QString filePathName = QFileDialog::getOpenFileName(nullptr,
                                                    ("文件对话框！"),
                                                    "F:",
                                                    ("音乐文件(*.mp3);;"));

    player = new QMediaPlayer(this);

    player->setMedia(QUrl::fromLocalFile(filePathName));

    player->play();
}

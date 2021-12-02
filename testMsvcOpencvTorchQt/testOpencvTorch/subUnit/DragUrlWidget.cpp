#include "DragUrlWidget.h"
#include "ui_DragUrlWidget.h"

#include <QDragEnterEvent>
#include <QMimeData>

#include <QImage>
#include <QPixmap>
#include <QString>

#include <QDebug>
#include <iostream>

#include <QHBoxLayout>

#include "CommonHandle.h"

using namespace std;

DragUrlWidget::DragUrlWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DragUrlWidget)
{
    ui->setupUi(this);
    this->setAcceptDrops(true);

    QHBoxLayout * hboxlayout = new QHBoxLayout(this);
    videoWidget = new QVideoWidget(this);
    player = new QMediaPlayer(this);
    ui->tab_2->setLayout(hboxlayout);
    hboxlayout->addWidget(videoWidget);
}

DragUrlWidget::~DragUrlWidget()
{
    delete ui;
}


void DragUrlWidget::dragEnterEvent(QDragEnterEvent* e)
{
    //dragEnterEvent 进入即相应，dropEvent 鼠标释放相应
    if (true)
    {
        e->acceptProposedAction();
    }
}
void DragUrlWidget::dropEvent(QDropEvent* e)
{
    //filepath
    QList<QUrl> urls = e->mimeData()->urls();
    if (urls.isEmpty()) return;
    QString qStr = urls.first().toLocalFile();


    //根据文件类型来做出对应的表达
    QString suffix = qStr.split(".").last();

    if(suffix == "jpg" || suffix == "png" ){
        ui->tabWidget->setCurrentWidget(ui->tab);
        QPixmap pixmap;
        pixmap.load(qStr);
        ui->label->setPixmap(pixmap);
    }
    else if(suffix == "wmv"){
        ui->tabWidget->setCurrentWidget(ui->tab_2);
        player->stop();

        player->setVideoOutput(videoWidget);    //设置视频由videoWidget对象执行

        player->setMedia(QUrl::fromLocalFile(qStr));    //设置视频本地路径

        player->play();                         //播放视频
    }
    else{
        qDebug() << "format error";
        ui->label->setText("format not support");
    }
}


QString DragUrlWidget::getCurrentFile()
{
    return this->m_currentFileName;
}




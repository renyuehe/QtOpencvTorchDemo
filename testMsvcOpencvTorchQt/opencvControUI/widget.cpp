#include "widget.h"
#include "ui_widget.h"

#include "BinaryThresholdUI.h"
#include "ChannelSpliteUI.h"
#include "ChannelRGBUI.h"
#include "VideoCaptureUI.h"
#include "MathAddweightedUI.h"
#include "WarpAffineUI.h"

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


void Widget::on_listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    QString itemStr = current->text();
    if(m_pCurrentWidget != nullptr){
        delete m_pCurrentWidget;
        m_pCurrentWidget = nullptr;
    }
    if(itemStr == "channelSpliteUI"){
        m_pCurrentWidget = new ChannelSpliteUI();
        ui->verticalLayout->addWidget(m_pCurrentWidget);
    }
    else if(itemStr == "channelRGBUi"){
        m_pCurrentWidget = new ChannelRGBUI();
        ui->verticalLayout->addWidget(m_pCurrentWidget);
    }
    else if(itemStr == "videoCaptureUI"){
        m_pCurrentWidget = new VideoCaptureUI();
        ui->verticalLayout->addWidget(m_pCurrentWidget);
    }
    else if(itemStr == "binaryThresholedUI"){
        m_pCurrentWidget = new BinaryThresholdUI();
        ui->verticalLayout->addWidget(m_pCurrentWidget);
    }
    else if(itemStr == "mathAddweightedUI"){
        m_pCurrentWidget = new MathAddweightedUI();
        ui->verticalLayout->addWidget(m_pCurrentWidget);
    }
    else if(itemStr == "warpAffineUI"){
        m_pCurrentWidget = new WarpAffineUI();
        ui->verticalLayout->addWidget(m_pCurrentWidget);
    }
}

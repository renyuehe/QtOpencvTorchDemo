#include "HWidget.h"
#include "ui_HWidget.h"

#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //动态分配空间，不能指定父对象
    myT = new HThread;

    //创建子线程
    thread = new QThread(this);

    //把自定义线程加入到子线程中
    myT->moveToThread(thread);

    connect(this, &Widget::startThread, myT, &HThread::myTimeout);
    //线程处理函数内部，不允许操作图形界面
    connect(myT, &HThread::mySignal, this, &Widget::dealSignal);
    connect(this, &Widget::destroyed, this, &Widget::dealClose);

    qDebug() << "main thread:" << QThread::currentThread();


    //connect()第五个参数的作用，连接方式：默认，队列，直接
    //多线程时才有意义
    //默认的时候
    //如果是多线程，默认使用队列
    //如果是单线程， 默认使用直接方式
    //队列: 槽函数所在的线程和接收者一样
    //直接：槽函数所在线程和发送者一样
}

Widget::~Widget()
{
    delete ui;
}

void Widget::dealClose()
{
    on_buttonStop_clicked();
    delete myT;
}

void Widget::dealSignal()
{
    static int i = 0;
    i++;
    ui->lcdNumber->display(i);
}

void Widget::on_buttonStart_clicked()
{
    if(thread->isRunning() == true)
    {
        return;
    }

    //启动线程，但是没有启动线程处理函数
    thread->start();
    myT->setFlag(false);

    //不能直接调用线程处理函数，
    //直接调用，导致，线程处理函数和主线程是在同一个线程
    //myT->myTimeout();

    //只能通过 signal - slot 方式调用
    emit startThread();
}

void Widget::on_buttonStop_clicked()
{
    if(thread->isRunning() == false)
    {
        return;
    }

    myT->setFlag(true);
    thread->quit();
    thread->wait();
}

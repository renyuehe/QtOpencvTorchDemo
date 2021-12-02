#include "Widget.h"
#include "ui_Widget.h"


#include<QtConcurrent>//要记得添加该头文件


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    myEnable = 0;//死循环标志位
}

void Widget::star()
{
    QtConcurrent::run(this,&Widget::xunhuan);//多线程执行死循环启动，可以带参数，具体格式可以查阅网上其它资料
}

void Widget::xunhuan()
{
    int i=0;
     while(myEnable)
     {
         i++;
         qDebug()<<i;
     }

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    myEnable = 1;
       xunhuan(); //非多线程执行死循环

}

void Widget::on_pushButton_2_clicked()
{
    myEnable=0;//标志位置零，退出死循环
       qDebug()<<"退出死循环!";
}

void Widget::on_pushButton_3_clicked()
{
    myEnable = 1;
        star();//多线程启动死循环
}

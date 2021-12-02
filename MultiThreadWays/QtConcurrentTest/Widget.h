#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    void star();//多线程启动函数，在原有的代码基础上增加该函数
    void xunhuan();//死循环函数，用这个函数代替原有代码的函数
    ~Widget();


private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();


private:
    Ui::Widget *ui;

    int myEnable;//标志位，用于退出死循环操作
};
#endif // WIDGET_H

#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "HThread.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT
public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void dealSignal();
    void dealClose();

signals:
    void startThread(); //启动子线程的信号

private slots:
    void on_buttonStart_clicked();

    void on_buttonStop_clicked();

private:
    Ui::Widget *ui;

    HThread *myT;
    QThread *thread;
};
#endif // WIDGET_H

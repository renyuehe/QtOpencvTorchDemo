#ifndef WIDGET_H
#define WIDGET_H

#include <QObject>
#include <QRunnable>

class PrintTask : public QObject, public QRunnable
{
    Q_OBJECT
public:
    PrintTask();
    ~PrintTask();
protected:
    void run();

signals:
    //注意！要使用信号，采用QObejct 和 QRunnable多继承，记得 QObject 要放在前面
    void mySignal();
};


#endif // WIDGET_H

#ifndef HTHREAD_H
#define HTHREAD_H

#include <QObject>
#include <QThread>

class HThread : public QObject
{
    Q_OBJECT
public:
    HThread(QObject *parent = nullptr);

    //线程处理函数
    void myTimeout();

    void setFlag(bool flag = true);

signals:
    void mySignal();

public slots:

private:
    bool isStop;
};

#endif // HTHREAD_H

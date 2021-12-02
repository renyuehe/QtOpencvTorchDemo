#include "PrintTask.h"
#include <QThread>
#include <iostream>
#include <QDebug>
using std::cout;
using std::endl;

PrintTask::PrintTask()
{
}

PrintTask::~PrintTask()
{

}

//线程真正执行的内容
void PrintTask::run()
{
//    cout << "PrintTask run 被调用，调用线程ID为：" << QThread::currentThread() << endl;
    qDebug() << "PrintTask run 被调用，调用线程ID为：" << QThread::currentThread();
}

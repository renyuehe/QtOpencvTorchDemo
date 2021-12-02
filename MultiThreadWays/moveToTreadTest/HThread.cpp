#include "HThread.h"
#include <QDebug>

HThread::HThread(QObject *parent)
{
    isStop = false;
}

void HThread::myTimeout()
{
    while( !isStop )
    {

        QThread::sleep(1);
        emit mySignal();
        //QMessageBox::aboutQt(NULL);

         qDebug() << "sub thread" << QThread::currentThread();

         if(isStop)
         {
             break;
         }
    }
}

void HThread::setFlag(bool flag)
{
    isStop = flag;
}


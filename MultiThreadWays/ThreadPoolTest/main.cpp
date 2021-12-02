#include <QCoreApplication>
#include <QThreadPool>
#include "PrintTask.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //设置最大线程数为3的一个线程池
    QThreadPool pool;
    pool.setMaxThreadCount(1);

    for(int i = 0; i < 8; i++)
    {
        pool.start(new PrintTask());
    }
    return a.exec();
}

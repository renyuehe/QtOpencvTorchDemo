#include "ComPluginManager.h"
#include <QApplication>
#include <QDir>
#include <QDebug>

ComPluginManager::ComPluginManager(QObject *parent)
    :QObject (parent)
{

}

void ComPluginManager::LoadAndInitAllPlugin()
{
    QDir pluginsDir(QApplication::applicationDirPath() + QStringLiteral("/plugin"));

    //遍历插件文件夹，加载插件文件
    Q_FOREACH(QString fileName, pluginsDir.entryList(QDir::Files))
    {
        QString strFilePath = pluginsDir.absoluteFilePath(fileName);
        LoadOnePlugin(strFilePath);
    }
}

#include <QPluginLoader>
void ComPluginManager::LoadOnePlugin(QString Path)
{
    QPluginLoader loader(Path);
    if(loader.load())
    {
        QObject *plugin = loader.instance();
        if (plugin)
        {
            ComPluginInterface* pComPluginInterface = qobject_cast<ComPluginInterface *>(plugin);//都可以

            if (pComPluginInterface)
            {
                //插件初始化
                pComPluginInterface->InitPlugin();

                //插件指针维护
                m_mapPluginInterface.insert(pComPluginInterface->PluginName(), pComPluginInterface);

                pComPluginInterface->CreateWidget(m_mapPluginWidget);
            }
        }
        else
        {
            qDebug() << QString("loader %1 library error!!\r\n").arg(Path);
        }
    }
    else
    {
        qDebug() << QString("%1 can not load !\r\n").arg(Path);
    }
}



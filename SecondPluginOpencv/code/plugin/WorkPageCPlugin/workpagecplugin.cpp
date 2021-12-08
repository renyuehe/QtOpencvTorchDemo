#include "workpagecplugin.h"
#include <QApplication>

WorkPageCPlugin::WorkPageCPlugin()
    :m_pSecondPluginWidget(nullptr)
{
}

void WorkPageCPlugin::InitPlugin()
{
    m_pSecondPluginWidget = Q_NULLPTR;
    m_pSecondPluginWidget = new SecondPluginWidget;


    QString dllpath = QApplication::applicationDirPath() + QStringLiteral("/plugin/WorkPageAPlugin.dll");

    LoadOneSecondPlugin(dllpath);
}

#include <QPluginLoader>
#include <QDebug>
void WorkPageCPlugin::LoadOneSecondPlugin(QString Path){
    QPluginLoader loader(Path);
    if(loader.load()){

        QObject *plugin = loader.instance();
        if(plugin){
            ComPluginInterface* pComPluginInterface = qobject_cast<ComPluginInterface *>(plugin);//都可以
            //插件初始化
            pComPluginInterface->InitPlugin();
            //获取插件界面
            QWidget *p_widget = pComPluginInterface->getWidget();
            if(m_pSecondPluginWidget && p_widget){
               m_pSecondPluginWidget->setCenterWidget(p_widget);
            }
        }
        else{
            qDebug() << "plugin emplty";
        }
    }
    else{
        qDebug() << "loader.load error";
    }
}


QString WorkPageCPlugin::PluginName()
{
    return QStringLiteral("WorkPageCPlugin");
}

QWidget *WorkPageCPlugin::getWidget()
{
    return m_pSecondPluginWidget;
}

void WorkPageCPlugin::CreateWidget(QMap<QString, QWidget *> &mapWidgets)
{
    if(m_pSecondPluginWidget){
        mapWidgets.insert(QStringLiteral(" secondPluginWidget"), m_pSecondPluginWidget);
    }
}

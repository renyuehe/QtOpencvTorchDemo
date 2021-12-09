#include "workpageaplugin.h"
#include <QPushButton>
#include <QDebug>

WorkPageAPlugin::WorkPageAPlugin(QObject *parent)
    :QObject(parent)
    ,p_pushbutton(nullptr)
{

}

void WorkPageAPlugin::InitPlugin()
{
    p_pushbutton = Q_NULLPTR;
    p_pushbutton = new QPushButton(QStringLiteral("pushbutton plugin"));
}

QString WorkPageAPlugin::PluginName()
{
    return QStringLiteral("WorkPageAPlugin");
}

QWidget *WorkPageAPlugin::getWidget()
{
    return this->p_pushbutton;
}

void WorkPageAPlugin::CreateWidget(QMap<QString, QWidget *> &mapWidgets)
{
    if (p_pushbutton)
    {
        mapWidgets.insert(QStringLiteral("pushbutton plugin"), p_pushbutton);
    }
}

void WorkPageAPlugin::SubPluginMsgCode(QList<int> &listSubCode)
{
    listSubCode << 0;
}

void WorkPageAPlugin::ProcessMsg(int code, const QVariant &varMsg)
{
    qDebug() << "消息接收";
}

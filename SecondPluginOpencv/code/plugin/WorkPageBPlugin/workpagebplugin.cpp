#include "workpagebplugin.h"

WorkPageBPlugin::WorkPageBPlugin()
{
}

void WorkPageBPlugin::InitPlugin()
{
    m_pWidget = Q_NULLPTR;
    m_pWidget = new QRadioButton;
}

QString WorkPageBPlugin::PluginName()
{
    return QStringLiteral("WorkPageBPlugin");
}

QWidget *WorkPageBPlugin::getWidget()
{
    return m_pWidget;
}

void WorkPageBPlugin::CreateWidget(QMap<QString, QWidget *> &mapWidgets)
{
    if(m_pWidget){
        mapWidgets.insert(QStringLiteral("radiobutton plugin"), m_pWidget);
    }
}

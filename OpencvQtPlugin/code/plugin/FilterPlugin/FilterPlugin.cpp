#include "FilterPlugin.h"

FilterPlugin::FilterPlugin()
{
}

void FilterPlugin::InitPlugin()
{
    m_pWidget = nullptr;
    m_pWidget = new FilterForm();
}

QString FilterPlugin::PluginName()
{
return QStringLiteral("FilterPlugin");
}

QWidget *FilterPlugin::getWidget()
{
    return m_pWidget;
}

void FilterPlugin::CreateWidget(QMap<QString, QWidget *> &mapWidgets)
{
    if(m_pWidget){
        mapWidgets.insert(QStringLiteral("Filter Widget"), m_pWidget);
    }
}

void FilterPlugin::SubPluginMsgCode(QList<int> &listSubCode)
{

}

void FilterPlugin::ProcessMsg(int code, const QVariant &varMsg)
{

}

#include "WorkSpaceWidget.h"
#include "QDebug"

WorkSpaceWidget::WorkSpaceWidget(QWidget *parent) : QWidget(parent)
{
    InitWorkSpaceWidget();
    LoadPluginAndFillWidget();
}

//初始化窗口
void WorkSpaceWidget::InitWorkSpaceWidget()
{
    m_pWorkTabWidget = new QTabWidget(this);
    m_pWorkTabWidget->resize(600,600);
}

void WorkSpaceWidget::LoadPluginAndFillWidget()
{
    m_pComPluginManager = new ComPluginManager;

    //加载所有插件
    m_pComPluginManager->LoadAndInitAllPlugin();


    //遍历插件获取分类信息
    const QMap<QString, ComPluginInterface*>& mapPluginInterface = m_pComPluginManager->m_mapPluginInterface;
    for (QMap<QString, ComPluginInterface*>::const_iterator iter = mapPluginInterface.constBegin(); iter != mapPluginInterface.constEnd(); ++iter)
    {
        qDebug() << iter.key() << __LINE__;
    }

    //遍历所有插件提供的窗口
    const QMap<QString, QWidget*>& mapPluginWidget = m_pComPluginManager->m_mapPluginWidget;
    for (QMap<QString, QWidget*>::const_iterator iter = mapPluginWidget.constBegin(); iter != mapPluginWidget.constEnd(); ++iter)
    {
        qDebug() << iter.key() << __LINE__;
        m_pWorkTabWidget->addTab(iter.value(), iter.key());
    }
}

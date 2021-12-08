#ifndef WORKPAGECPLUGIN_H
#define WORKPAGECPLUGIN_H

#include "WorkPageCPlugin_global.h"
#include "ComPluginInterface.h"
#include <QObject>
#include "secondpluginwidget.h"

class WORKPAGECPLUGIN_EXPORT WorkPageCPlugin : public QObject, public ComPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID ComPluginInterface_IID)
    Q_INTERFACES(ComPluginInterface)

private:
    SecondPluginWidget * m_pSecondPluginWidget;

public:
    WorkPageCPlugin();

    /**
     * @brief InitPlugin 插件初始化
     */
    void InitPlugin() override;

    /**
     * @brief RegisterPluginName 插件名注册
     * @return
     */
    QString PluginName() override;

    QWidget * getWidget() override;

    /**
     * @brief CreateWidget 创建插件界面
     * @param mapWidgets 窗口名称映射<窗口名称, 窗口>
     */
    void CreateWidget(QMap<QString, QWidget*>& mapWidgets) override;

    /**
     * @brief LoadOneSecondPlugin 加载所有的耳机插件
     */
    void LoadOneSecondPlugin(QString path);
};

#endif // WORKPAGECPLUGIN_H

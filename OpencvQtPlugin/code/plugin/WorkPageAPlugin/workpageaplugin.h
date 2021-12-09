#ifndef WORKPAGEAPLUGIN_H
#define WORKPAGEAPLUGIN_H

#include "WorkPageAPlugin_global.h"
#include <QWidget>
#include <QPushButton>
#include "ComPluginInterface.h"


class WORKPAGEAPLUGIN_EXPORT WorkPageAPlugin : public QObject, public ComPluginInterface
{

    Q_OBJECT
    Q_PLUGIN_METADATA(IID ComPluginInterface_IID)

    // 将该接口注册到Qt的meta-object system
    Q_INTERFACES(ComPluginInterface)

public:
    WorkPageAPlugin(QObject *parent=nullptr);

    QPushButton * p_pushbutton;
public:

    void InitPlugin() override;

    QString PluginName() override;

    QWidget * getWidget() override;

    void CreateWidget(QMap<QString, QWidget*>& mapWidgets) override;

    /**
     * @brief SubPluginMsgCode 消息发布和订阅编号列表
     * @param listSubCode 订阅编号列表
     */
    void SubPluginMsgCode(QList<int>& listSubCode) override;
    /**
     * @brief ProcessMsg 消息接收---接收来自插件管理器的消息
     * @param code  消息号
     * @param Msg   消息体
     */
    void ProcessMsg(int code, const QVariant& varMsg) override;
};

#endif // WORKPAGEAPLUGIN_H

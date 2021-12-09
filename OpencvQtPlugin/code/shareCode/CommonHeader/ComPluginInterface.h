#ifndef COMPLUGININTERFACE_H
#define COMPLUGININTERFACE_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QJsonObject>
#include <QVariant>
#include <QVector>
#include <QPixmap>

class ComPluginInterface /*: public QObject*/
{
public:
    virtual ~ComPluginInterface(){}

    /**
     * @brief InitPlugin 插件初始化
     */
    virtual void InitPlugin() = 0;

    /**
     * @brief RegisterPluginName 插件名注册
     * @return
     */
    virtual QString PluginName() = 0;

    virtual QWidget * getWidget() = 0;

    /**
     * @brief CreateWidget 创建插件界面
     * @param mapWidgets 窗口名称映射<窗口名称, 窗口>
     */
    virtual void CreateWidget(QMap<QString, QWidget*>& mapWidgets) = 0;

    ///////////////// 消息发布订阅 ///////////////////
    /**
     * @brief SubPluginMsgCode 消息发布和订阅编号列表
     * @param listSubCode 订阅编号列表
     */
    virtual void SubPluginMsgCode(QList<int>& listSubCode) = 0;

    /**
     * @brief ProcessMsg 消息接收---接收来自插件管理器的消息
     * @param code  消息号
     * @param Msg   消息体
     */
    virtual void ProcessMsg(int code, const QVariant& varMsg) = 0;


};

QT_BEGIN_NAMESPACE

#define ComPluginInterface_IID "org.qt-project.Qt.ComPluginInterface/1.0"

//此宏用于把标识符与类名接口关联起来。这个标识符是唯一的
Q_DECLARE_INTERFACE(ComPluginInterface, ComPluginInterface_IID)

QT_END_NAMESPACE

#endif // COMPLUGININTERFACE_H

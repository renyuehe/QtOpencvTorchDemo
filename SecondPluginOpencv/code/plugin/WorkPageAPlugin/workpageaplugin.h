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
};

#endif // WORKPAGEAPLUGIN_H

#ifndef WORKPAGEBPLUGIN_H
#define WORKPAGEBPLUGIN_H

#include "WorkPageBPlugin_global.h"
#include "ComPluginInterface.h"
#include <QObject>
#include <QRadioButton>

class WORKPAGEBPLUGIN_EXPORT WorkPageBPlugin : public QObject, public ComPluginInterface
{
    Q_OBJECT

    Q_PLUGIN_METADATA(IID ComPluginInterface_IID)
    Q_INTERFACES(ComPluginInterface)

    QRadioButton * m_pWidget;
public:
    WorkPageBPlugin();

    void InitPlugin() override;

    QString PluginName() override;

    QWidget * getWidget() override;

    void CreateWidget(QMap<QString, QWidget*>& mapWidgets) override;
};

#endif // WORKPAGEBPLUGIN_H

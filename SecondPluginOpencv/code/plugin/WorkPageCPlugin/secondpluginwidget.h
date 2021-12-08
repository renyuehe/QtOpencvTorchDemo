#ifndef SECONDPLUGINWIDGET_H
#define SECONDPLUGINWIDGET_H

#include <QWidget>

namespace Ui {
class SecondPluginWidget;
}

class SecondPluginWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SecondPluginWidget(QWidget *parent = nullptr);
    ~SecondPluginWidget();

    void setCenterWidget(QWidget *);

private:
    Ui::SecondPluginWidget *ui;
};

#endif // SECONDPLUGINWIDGET_H

#include "secondpluginwidget.h"
#include "ui_secondpluginwidget.h"

SecondPluginWidget::SecondPluginWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SecondPluginWidget)
{
    ui->setupUi(this);
}

SecondPluginWidget::~SecondPluginWidget()
{
    delete ui;
}

void SecondPluginWidget::setCenterWidget(QWidget * widget)
{
    this->ui->scrollArea->setWidget(widget);
}

#include "FilterForm.h"
#include "ui_FilterForm.h"
#include <QDebug>
#include "Communication.h"

FilterForm::FilterForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FilterForm)
{
    ui->setupUi(this);
}

FilterForm::~FilterForm()
{
    delete ui;
}

#include "opencv2/highgui.hpp"
#include "opencv2/world.hpp"
#include "opencv2/core.hpp"
using namespace cv;
void FilterForm::on_pushButton_clicked()
{
    qDebug() << &SRC_IMG;
    qDebug() << &SRC_IMG;

    ui->label->setPixmap(SRC_IMG);
}

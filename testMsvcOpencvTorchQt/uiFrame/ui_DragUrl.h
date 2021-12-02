/********************************************************************************
** Form generated from reading UI file 'DragUrl.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DRAGURL_H
#define UI_DRAGURL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DragUrl
{
public:
    QGridLayout *gridLayout;
    QLineEdit *lineEdit;
    QLabel *label;

    void setupUi(QWidget *DragUrl)
    {
        if (DragUrl->objectName().isEmpty())
            DragUrl->setObjectName(QString::fromUtf8("DragUrl"));
        DragUrl->resize(400, 300);
        gridLayout = new QGridLayout(DragUrl);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lineEdit = new QLineEdit(DragUrl);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout->addWidget(lineEdit, 0, 0, 1, 1);

        label = new QLabel(DragUrl);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);


        retranslateUi(DragUrl);

        QMetaObject::connectSlotsByName(DragUrl);
    } // setupUi

    void retranslateUi(QWidget *DragUrl)
    {
        DragUrl->setWindowTitle(QCoreApplication::translate("DragUrl", "Form", nullptr));
        label->setText(QCoreApplication::translate("DragUrl", "\346\213\226\346\213\275", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DragUrl: public Ui_DragUrl {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DRAGURL_H

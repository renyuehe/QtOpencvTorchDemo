/********************************************************************************
** Form generated from reading UI file 'DragUrlWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DRAGURLWIDGET_H
#define UI_DRAGURLWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DragUrlWidget
{
public:
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit;
    QLabel *label;

    void setupUi(QWidget *DragUrlWidget)
    {
        if (DragUrlWidget->objectName().isEmpty())
            DragUrlWidget->setObjectName(QString::fromUtf8("DragUrlWidget"));
        DragUrlWidget->resize(400, 300);
        verticalLayout = new QVBoxLayout(DragUrlWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lineEdit = new QLineEdit(DragUrlWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        verticalLayout->addWidget(lineEdit);

        label = new QLabel(DragUrlWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFrameShape(QFrame::StyledPanel);
        label->setFrameShadow(QFrame::Plain);
        label->setLineWidth(2);
        label->setMidLineWidth(1);

        verticalLayout->addWidget(label);


        retranslateUi(DragUrlWidget);

        QMetaObject::connectSlotsByName(DragUrlWidget);
    } // setupUi

    void retranslateUi(QWidget *DragUrlWidget)
    {
        DragUrlWidget->setWindowTitle(QCoreApplication::translate("DragUrlWidget", "Form", nullptr));
        label->setText(QCoreApplication::translate("DragUrlWidget", "\346\213\226\345\205\245", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DragUrlWidget: public Ui_DragUrlWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DRAGURLWIDGET_H

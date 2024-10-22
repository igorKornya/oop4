/********************************************************************************
** Form generated from reading UI file 'interface.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTERFACE_H
#define UI_INTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_interface
{
public:

    void setupUi(QWidget *interface)
    {
        if (interface->objectName().isEmpty())
            interface->setObjectName(QString::fromUtf8("interface"));
        interface->resize(721, 592);

        retranslateUi(interface);

        QMetaObject::connectSlotsByName(interface);
    } // setupUi

    void retranslateUi(QWidget *interface)
    {
        interface->setWindowTitle(QCoreApplication::translate("interface", "interface", nullptr));
    } // retranslateUi

};

namespace Ui {
    class interface: public Ui_interface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERFACE_H

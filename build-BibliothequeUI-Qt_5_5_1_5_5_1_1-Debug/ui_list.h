/********************************************************************************
** Form generated from reading UI file 'list.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LIST_H
#define UI_LIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_list
{
public:
    QLabel *label;

    void setupUi(QDialog *list)
    {
        if (list->objectName().isEmpty())
            list->setObjectName(QStringLiteral("list"));
        list->resize(400, 300);
        label = new QLabel(list);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(120, 170, 60, 16));

        retranslateUi(list);

        QMetaObject::connectSlotsByName(list);
    } // setupUi

    void retranslateUi(QDialog *list)
    {
        list->setWindowTitle(QApplication::translate("list", "Dialog", 0));
        label->setText(QApplication::translate("list", "List", 0));
    } // retranslateUi

};

namespace Ui {
    class list: public Ui_list {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LIST_H

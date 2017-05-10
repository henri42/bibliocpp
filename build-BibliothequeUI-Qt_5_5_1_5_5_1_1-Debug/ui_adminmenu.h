/********************************************************************************
** Form generated from reading UI file 'adminmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINMENU_H
#define UI_ADMINMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_adminMenu
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton_5;
    QPushButton *pushButton;
    QPushButton *pushButton_4;
    QLineEdit *lineEdit;
    QPushButton *pushButton_6;

    void setupUi(QDialog *adminMenu)
    {
        if (adminMenu->objectName().isEmpty())
            adminMenu->setObjectName(QStringLiteral("adminMenu"));
        adminMenu->setEnabled(true);
        adminMenu->resize(400, 300);
        gridLayoutWidget = new QWidget(adminMenu);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(30, 100, 321, 71));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_3 = new QPushButton(gridLayoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 1, 2, 1, 1);

        pushButton_2 = new QPushButton(gridLayoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 1, 1, 1, 1);

        pushButton_5 = new QPushButton(gridLayoutWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        gridLayout->addWidget(pushButton_5, 1, 3, 1, 1);

        pushButton = new QPushButton(gridLayoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 1, 0, 1, 1);

        pushButton_4 = new QPushButton(gridLayoutWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        gridLayout->addWidget(pushButton_4, 1, 4, 1, 1);

        lineEdit = new QLineEdit(gridLayoutWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setEnabled(true);

        gridLayout->addWidget(lineEdit, 0, 0, 1, 4);

        pushButton_6 = new QPushButton(gridLayoutWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));

        gridLayout->addWidget(pushButton_6, 0, 4, 1, 1);


        retranslateUi(adminMenu);

        QMetaObject::connectSlotsByName(adminMenu);
    } // setupUi

    void retranslateUi(QDialog *adminMenu)
    {
        adminMenu->setWindowTitle(QApplication::translate("adminMenu", "Dialog", 0));
        pushButton_3->setText(QApplication::translate("adminMenu", "P", 0));
        pushButton_2->setText(QApplication::translate("adminMenu", "P", 0));
        pushButton_5->setText(QApplication::translate("adminMenu", "P", 0));
        pushButton->setText(QApplication::translate("adminMenu", "List", 0));
        pushButton_4->setText(QApplication::translate("adminMenu", "P", 0));
        pushButton_6->setText(QApplication::translate("adminMenu", "PushButton", 0));
    } // retranslateUi

};

namespace Ui {
    class adminMenu: public Ui_adminMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINMENU_H

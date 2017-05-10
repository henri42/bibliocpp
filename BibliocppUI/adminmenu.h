#ifndef ADMINMENU_H
#define ADMINMENU_H

#include<QApplication>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QBoxLayout>
#include <QGridLayout>

class adminMenu : public QWidget
{
private:
    QGridLayout *layout;

    QPushButton* list;
    QPushButton* reset;
    QPushButton* load;
    QPushButton* save;
    QPushButton* add;
    QPushButton* del;

    QLineEdit* search;
public:
    adminMenu();
};

#endif // ADMINMENU_H

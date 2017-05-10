#ifndef ADMINMENU_H
#define ADMINMENU_H

#include<QApplication>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>

class adminMenu : public QWidget
{
private:
    QPushButton* list;
    QPushButton* reset;
    QPushButton* load;
    QPushButton* save;
    QPushButton* add;
    QPushButton* del;

    QLineEdit* search;
public:
    adminMenu();
    ~adminMenu();

signals:

public slots:

};

#endif // ADMINMENU_H

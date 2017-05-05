#ifndef MAINWIN_H
#define MAINWIN_H

#include<QApplication>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>

class mainWin : public QWidget
{
private:
    QPushButton* list;
    QPushButton* reset;
    QPushButton* load;
    QPushButton* save;
    QPushButton* add;
    QPushButton* del;

    QPushButton* empr;
    QPushButton* res;
    QPushButton* rendre;

    QPushButton* logout;
    QPushButton* login;

    QLineEdit* username;
    QLineEdit* password;
    QLineEdit* search;



public:
    mainWin();
    ~mainWin();

};


#endif // MAINWIN_H

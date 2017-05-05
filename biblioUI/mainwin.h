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
<<<<<<< HEAD


=======
>>>>>>> fcfe15793f92d6597459fce50540a943b742321d
};


#endif // MAINWIN_H

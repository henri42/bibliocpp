#ifndef ADMINMENU_H
#define ADMINMENU_H

#include<QApplication>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>

class adminMenu : public QWidget
{
public:
    QPushButton* list;
    QPushButton* reset;
    QPushButton* load;
    QPushButton* save;
    QPushButton* add;
    QPushButton* del;
    QPushButton* logout;
    QPushButton* help;
    QPushButton* go;

    QLineEdit* search;

    QLabel* names;
    QLabel* title;
    QLabel* bibliozer;

    QString text_search;
public:
    adminMenu(QWidget* conteneur);
    ~adminMenu();

signals:

public slots:

};

#endif // ADMINMENU_H

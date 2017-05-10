#ifndef CLIENTMENU_H
#define CLIENTMENU_H

#include<QApplication>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>

class clientMenu : public QWidget
{
public:
    QPushButton* list;
    QPushButton* logout;

    QLineEdit* search;

    QLabel* names;
    QLabel* title;
    QLabel* bibliozer;

public:
    clientMenu(QWidget* conteneur);
    ~clientMenu();

signals:

public slots:

};

#endif // CLIENTMENU_H

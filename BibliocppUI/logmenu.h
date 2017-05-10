#ifndef LOGMENU_H
#define LOGMENU_H

#include<QApplication>
#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QMessageBox>

class logMenu : public QWidget
{
public:
    QPushButton* logout;
    QPushButton* login;

    QLineEdit* username;
    QLineEdit* password;

    QLabel* names;
    QLabel* title;
    QLabel* bibliozer;

    QString text_username;
    QString text_password;

public:
    logMenu(QWidget* conteneur);
    ~logMenu();

signals:

public slots:

};

#endif // LOGMENU_H

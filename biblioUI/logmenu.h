#ifndef LOGMENU_H
#define LOGMENU_H

#include<QApplication>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>

class logMenu : public QWidget
{
private:
    QPushButton* logout;
    QPushButton* login;

    QLineEdit* username;
    QLineEdit* password;
public:


signals:

public slots:

};

#endif // LOGMENU_H

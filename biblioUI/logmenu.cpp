#include "logmenu.h"

logMenu::logMenu() : QWidget()
{
    setFixedSize(800,600);

    //construction des widgets
    login = new QPushButton("Connexion",this);
    logout = new QPushButton("Deconnexion",this);

    username = new QLineEdit(this);
    password = new QLineEdit(this);

    username->move(400-username->width()/2,260);
    password->move(username->x(),username->y()+30);
    login->move(400-login->width()/2,username->y()+60);
    logout->move(800 - logout->width(),0);
}

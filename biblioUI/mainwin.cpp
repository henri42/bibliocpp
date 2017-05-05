#include "mainwin.h"

mainWin::mainWin() : QWidget()
{
    setFixedSize(800,600);
    setWindowTitle("Bibliozer");

    add = new QPushButton("hide reset",this);
    del = new QPushButton("show reset",this);
    add->move(0,0);
    del->move(add->x()+100,add->y());

    username = new QLineEdit(this);
    password = new QLineEdit(this);
    login = new QPushButton("Connexion",this);

    username->setPlaceholderText("Nom d'utilisateur");
    password->setPlaceholderText("Mot de passe");
    password->setEchoMode(QLineEdit::Password);

    username->move(400-username->width()/2,260);
    password->move(username->x(),username->y()+30);
    login->move(400-login->width()/2,username->y()+60);

    QObject::connect(add,SIGNAL(clicked()),login,SLOT(hide()));
    QObject::connect(del,SIGNAL(clicked()),login,SLOT(show()));

}

mainWin::~mainWin()
{
    delete add;
    delete username;
    delete password;
    delete login;
}

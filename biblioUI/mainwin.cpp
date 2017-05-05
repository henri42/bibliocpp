#include "mainwin.h"

mainWin::mainWin() : QWidget()
{
    setFixedSize(800,600);
    setWindowTitle("Bibliozer");

    //construction dynamique des widgets
    add = new QPushButton("Ajouter",this);
    del = new QPushButton("Supprimer",this);
    load = new QPushButton("Charger",this);
    save = new QPushButton("Sauvegarder",this);
    list = new QPushButton("Parcourir Médiathèque",this);

    //placement
    add->move(300,400);
    del->move(add->x(),add->y() + 30);
    load->move(add->x()+100,add->y());
    save->move(del->x()+100,del->y());

    username = new QLineEdit(this);
    password = new QLineEdit(this);
    login = new QPushButton("Connexion",this);

    username->setPlaceholderText("Nom d'utilisateur");
    password->setPlaceholderText("Mot de passe");
    password->setEchoMode(QLineEdit::Password);



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


#include "logmenu.h"
#define LARGEUR_BTN 100
#define HAUTEUR_BTN 20

logMenu::logMenu(QWidget* conteneur) : QWidget(conteneur)
{
    setFixedSize(800,600);

    //construction des widgets
    login = new QPushButton("Connexion",this);
    logout = new QPushButton("Deconnexion",this);

    username = new QLineEdit(this);
    password = new QLineEdit(this);

    names = new QLabel("© Gouttard-Papandinas");
    title = new QLabel("Projet C++ 2017");

    //tailles
    logout->setFixedSize(LARGEUR_BTN,HAUTEUR_BTN);
    login->setFixedSize(LARGEUR_BTN,HAUTEUR_BTN);
    username->setFixedSize(LARGEUR_BTN+20,HAUTEUR_BTN);
    password->setFixedSize(LARGEUR_BTN+20,HAUTEUR_BTN);
    //positions
    username->move(400-username->width()/2,260);
    password->move(username->x(),username->y()+30);
    login->move(400-login->width()/2,username->y()+60);
    logout->move(800-logout->width()-5,5);
    names->move(0,550);
    title->move(400,550);

    //autre
    username->setPlaceholderText("Nom d'utilisateur");
    password->setPlaceholderText("Mot de passe");
    password->setEchoMode(QLineEdit::Password);

}

logMenu::~logMenu()
{

}

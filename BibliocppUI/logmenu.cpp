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

    names = new QLabel(this);
    title = new QLabel(this);

    bibliozer = new QLabel(this);


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
    names->move(5,580);
<<<<<<< HEAD
    title->move(695,580);
=======
    title->move(700,580);
    bibliozer->move(205,100);
>>>>>>> b415c2030cd0de21f763b4577913034b020eac3e

    //autre
    username->setPlaceholderText("Nom d'utilisateur");
    password->setPlaceholderText("Mot de passe");
    password->setEchoMode(QLineEdit::Password);
    names->setText("© Gouttard-Papandinas");
    title->setText("Projet C++ 2017");
    bibliozer->setPixmap(QPixmap("bibliozer.gif").scaled(4*(bibliozer->width()),4*(bibliozer->height()),Qt::KeepAspectRatio));
    bibliozer->show();


}

logMenu::~logMenu()
{

}

#include "clientmenu.h"
#define LARGEUR_BTN 100
#define HAUTEUR_BTN 20

clientMenu::clientMenu(QWidget* conteneur) : QWidget(conteneur)
{
    setFixedSize(800,600);
    setWindowTitle("Bibliozer");

    //construction des widgets
    list = new QPushButton("Parcourir la mediatheque",this);
    logout = new QPushButton("Deconnexion",this);

    search = new QLineEdit(this);

    names = new QLabel(this);
    title = new QLabel(this);

    bibliozer = new QLabel(this);

    //tailles
    list->setFixedSize(5*LARGEUR_BTN+50,HAUTEUR_BTN);
    search->setFixedSize(5*LARGEUR_BTN+50,HAUTEUR_BTN);
    logout->setFixedSize(LARGEUR_BTN,HAUTEUR_BTN);


    //positions
    search->move(400-search->width()/2,260);
    list->move(400-list->width()/2,search->y()+60);
    logout->move(800-logout->width()-5,5);
    names->move(5,580);
    title->move(700,580);
    bibliozer->move(205,100);


    //autre
    search->setPlaceholderText("Recherche");
    names->setText("© Gouttard-Papandinas");
    title->setText("Projet C++ 2017");
    bibliozer->setPixmap(QPixmap("bibliozer.gif").scaled(4*(bibliozer->width()),4*(bibliozer->height()),Qt::KeepAspectRatio));
    bibliozer->show();

}

clientMenu::~clientMenu()
{

}

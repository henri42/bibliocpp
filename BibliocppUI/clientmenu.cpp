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


    //tailles
    list->setFixedSize(5*LARGEUR_BTN+50,HAUTEUR_BTN);
    search->setFixedSize(5*LARGEUR_BTN+50,HAUTEUR_BTN);
    logout->setFixedSize(LARGEUR_BTN,HAUTEUR_BTN);


    //positions
    search->move(400-search->width()/2,260);
    list->move(400-list->width()/2,search->y()+60);
    logout->move(800-logout->width()-5,5);


    //autre
    search->setPlaceholderText("Recherche");

}

clientMenu::~clientMenu()
{

}

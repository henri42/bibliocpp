#include "adminmenu.h"
#define LARGEUR_BTN 100
#define HAUTEUR_BTN 20

adminMenu::adminMenu(QWidget* conteneur) : QWidget(conteneur)
{
    setFixedSize(800,600);
    setWindowTitle("Bibliozer");

    //construction des widgets
    add = new QPushButton("Ajouter",this);
    del = new QPushButton("Supprimer",this);
    load = new QPushButton("Charger",this);
    save = new QPushButton("Sauvegarder",this);
    list = new QPushButton("Parcourir",this);
    logout = new QPushButton("Deconnexion",this);
    help = new QPushButton("?",this);


    search = new QLineEdit(this);


    //tailles
    add->setFixedSize(LARGEUR_BTN,HAUTEUR_BTN);
    del->setFixedSize(LARGEUR_BTN,HAUTEUR_BTN);
    load->setFixedSize(LARGEUR_BTN,HAUTEUR_BTN);
    save->setFixedSize(LARGEUR_BTN,HAUTEUR_BTN);
    list->setFixedSize(LARGEUR_BTN,HAUTEUR_BTN);
    search->setFixedSize(5*LARGEUR_BTN+50,HAUTEUR_BTN);
    logout->setFixedSize(LARGEUR_BTN,HAUTEUR_BTN);
    help->setFixedSize(HAUTEUR_BTN,HAUTEUR_BTN);


    //positions
    search->move(400-search->width()/2,260);
    list->move(175-list->width()/2,search->y()+60);
    load->move(287-load->width()/2,search->y()+60);
    save->move(400-save->width()/2,search->y()+60);
    add->move(512-add->width()/2,search->y()+60);
    del->move(625-del->width()/2,search->y()+60);
    logout->move(800-logout->width()-5,5);
    help->move(0+help->width()-5,5);


    //autre
    search->setPlaceholderText("Recherche");

}

adminMenu::~adminMenu()
{

}

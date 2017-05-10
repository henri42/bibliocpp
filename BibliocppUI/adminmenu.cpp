#include "adminmenu.h"

adminMenu::adminMenu()
{
    setFixedSize(800,600);
    setWindowTitle("Bibliozer");

    QWidget *fenetre = new QWidget;
    fenetre->setFixedSize(300, 150);

    add = new QPushButton("Ajouter",this);
    del = new QPushButton("Supprimer",this);
    load = new QPushButton("Charger",this);
    save = new QPushButton("Sauvegarder",this);
    list = new QPushButton("Parcourir Médiathèque",this);

    search = new QLineEdit(this);

    layout = new QGridLayout(fenetre);

    search->setPlaceholderText("Recherche");

    layout->addWidget(list, 0, 0);
    layout->addWidget(add, 0, 1);
    layout->addWidget(del, 1, 0);
    layout->addWidget(load, 1, 1);
    layout->addWidget(save, 2, 0, 1, 2);

    setLayout(layout);
    //layout->addSpacing(100);
    //layout->insertSpacing(0,100);

}

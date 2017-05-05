#include "adminmenu.h"

adminmenu::adminmenu()
{
    setFixedSize(800,600);
    setWindowTitle("Bibliozer");

    add = new QPushButton("Ajouter",this);
    del = new QPushButton("Supprimer",this);
    load = new QPushButton("Charger",this);
    save = new QPushButton("Sauvegarder",this);
    list = new QPushButton("Parcourir Médiathèque",this);

    search = new QLineEdit(this);

    layout = new QHBoxLayout;

    search->setPlaceholderText("Recherche");

    layout->addWidget(list);
    layout->addWidget(add);
    layout->addWidget(del);
    layout->addWidget(load);
    layout->addWidget(save);

    setLayout(layout);
    layout->addSpacing(100);
    layout->insertSpacing(0,100);


}

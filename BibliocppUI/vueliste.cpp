#include "vueliste.h"

using namespace std;

vueListe::vueListe(QWidget* parent) : QWidget(parent)
{
    setFixedSize(800,600);
    m_liste_item = new QListWidget(this);

    m_liste_item->setFixedSize(600,400);
    m_liste_item->move(100,100);

    m_liste_item->addItem("salut");
    m_liste_item->item(0)->setIcon(QIcon("/Users/Sophie/bibliocpp/build-BibliocppUI-Desktop_Qt_5_8_0_clang_64bit-Debug/livre.png"));
    m_liste_item->addItem("cava");

    vector<string> a = { "je" , "vais" , "ici" };
    loadListe(a);


}

void vueListe::loadListe(vector<string> liste_noms)
{
    int taille = liste_noms.size();
    for (int i = 0; i<taille; i++)
       m_liste_item->addItem(QString(liste_noms[i].c_str()));
}

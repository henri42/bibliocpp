#include "vueliste.h"

using namespace std;

vueListe::vueListe(QWidget* parent) : QWidget(parent)
{
    setFixedSize(800,600);
    m_liste = new QListWidget(this);

    m_liste->setFixedSize(600,400);
    m_liste->move(100,100);

    m_liste->addItem("salut");
    m_liste->addItem("cava");


}

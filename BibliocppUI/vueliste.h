#ifndef VUELIST_H
#define VUELIST_H

#include <QApplication>
#include <QWidget>
#include <QListWidget>
#include <QPushButton>
#include <QListWidgetItem>
#include <vector>
#include <string>

class vueListe : public QWidget
{
public:
    QListWidget* m_liste_item;

public:
    vueListe(QWidget* parent);

    void loadListe(std::vector<std::string> liste_noms);
};

#endif // VUELIST_H

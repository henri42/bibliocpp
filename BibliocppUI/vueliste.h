#ifndef VUELIST_H
#define VUELIST_H

#include <QApplication>
#include <QWidget>
#include <QListWidget>
#include <QPushButton>
#include <QListWidgetItem>
#include <vector>

class vueListe : public QWidget
{
public:
    QListWidget* m_liste;

public:
    vueListe(QWidget* parent);
};

#endif // VUELIST_H

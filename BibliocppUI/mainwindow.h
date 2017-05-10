#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include "adminmenu.h"
#include "logmenu.h"
#include "vueliste.h"
#include "clientmenu.h"

class mainWindow : public QWidget
{

Q_OBJECT

public:
    logMenu* m_logmenu;
    adminMenu* m_adminmenu;
    vueListe* m_liste;
    clientMenu* m_clientmenu;


public:
    mainWindow();

public slots:
    void connexion();
};

#endif // MAINWINDOW_H

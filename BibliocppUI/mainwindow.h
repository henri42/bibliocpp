#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include "adminmenu.h"
#include "logmenu.h"
#include "vueliste.h"

class mainWindow : public QWidget
{
public:
    logMenu* m_logmenu;
    adminMenu* m_adminmenu;
    vueListe* m_liste;

public:
    mainWindow();
};

#endif // MAINWINDOW_H

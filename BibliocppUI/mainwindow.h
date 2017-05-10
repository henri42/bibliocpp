#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include "adminmenu.h"
#include "logmenu.h"

class mainWindow : public QWidget
{
public:
    logMenu* m_logmenu;
    adminMenu* m_adminmenu;

public:
    mainWindow();
};

#endif // MAINWINDOW_H

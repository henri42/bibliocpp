#include "mainwindow.h"

mainWindow::mainWindow() : QWidget()
{
    m_logmenu = new logMenu(this);
    m_adminmenu = new adminMenu(this);
}

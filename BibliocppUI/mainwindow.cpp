#include "mainwindow.h"

mainWindow::mainWindow() : QWidget()
{
    m_logmenu = new logMenu(this);
    m_adminmenu = new adminMenu(this);
    m_adminmenu->hide();

    QObject::connect(m_logmenu->login, SIGNAL(clicked()), m_logmenu, SLOT(hide()));
    QObject::connect(m_logmenu->login, SIGNAL(clicked()), m_adminmenu, SLOT(show()));
}


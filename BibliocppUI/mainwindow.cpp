#include "mainwindow.h"

mainWindow::mainWindow() : QWidget()
{
    m_logmenu = new logMenu(this);
    m_adminmenu = new adminMenu(this);
    m_liste = new vueListe(this);
    m_clientmenu = new clientMenu(this);

    m_adminmenu->hide();
    m_clientmenu->hide();
    m_liste->hide();

    QObject::connect(m_logmenu->login, SIGNAL(clicked()), this, SLOT(connexion()));

    QObject::connect(m_adminmenu->logout, SIGNAL(clicked()), m_adminmenu, SLOT(hide()));
    QObject::connect(m_adminmenu->logout, SIGNAL(clicked()), m_logmenu, SLOT(show()));

    QObject::connect(m_clientmenu->logout, SIGNAL(clicked()), m_clientmenu, SLOT(hide()));
    QObject::connect(m_clientmenu->logout, SIGNAL(clicked()), m_logmenu, SLOT(show()));
}

void mainWindow::connexion()
{
    m_logmenu->text_username = (m_logmenu->username)->text();
    m_logmenu->text_password = (m_logmenu->password)->text();

    if(m_logmenu->text_username ==  "admin" && m_logmenu->text_password == "admin")
    {
        QMessageBox::information(this, "Login", "Username and password is correct, Admin connexion");
        m_adminmenu->show();
        m_logmenu->hide();
    }
    else
    {
        QMessageBox::warning(this,"Login", "Username and password is not correct, Client connexion");
        m_clientmenu->show();
        m_logmenu->hide();
    }
}

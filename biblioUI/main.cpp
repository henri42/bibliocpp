#include <QApplication>
#include <QPushButton>
#include <QBoxLayout>
#include "mainwin.h"
#include "logmenu.h"
#include "adminmenu.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    adminmenu test;

    test.show();

    return app.exec();
}

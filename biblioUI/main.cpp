#include <QApplication>
#include <QPushButton>
#include "mainwin.h"
#include "logmenu.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    logMenu test;

    test.show();

    return app.exec();
}

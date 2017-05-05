#include <QApplication>
#include <QPushButton>
#include "mainwin.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    mainWin test;

    test.show();

    return app.exec();
}

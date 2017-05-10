#include "adminmenu.h"
#include "logmenu.h"
#include "mainwindow.h"
#include "clientmenu.h"

#include <QApplication>
#include <QPushButton>
#include <QBoxLayout>

int main(int argc, char *argv[])
{
        QApplication app(argc, argv);

        mainWindow testMW;
        testMW.show();

        return app.exec();
}

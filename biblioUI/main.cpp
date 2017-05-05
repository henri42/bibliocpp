#include <QApplication>
#include <QPushButton>
#include <QBoxLayout>
#include "mainwin.h"
<<<<<<< HEAD
#include "logmenu.h"
=======
#include "adminmenu.h"
>>>>>>> 79ac884edee2ac9190518b82ec2ad54d63a9a332


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

<<<<<<< HEAD
    logMenu test;
=======
    adminmenu test;
>>>>>>> 79ac884edee2ac9190518b82ec2ad54d63a9a332

    test.show();

    return app.exec();
}

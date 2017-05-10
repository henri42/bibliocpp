#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "adminmenu.h"

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    adminMenu *fenetre2;
};

#endif // MAINWINDOW_H

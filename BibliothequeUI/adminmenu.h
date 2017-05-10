#ifndef ADMINMENU_H
#define ADMINMENU_H

#include <QDialog>
#include "list.h"

namespace Ui {
class adminMenu;
}

class adminMenu : public QDialog
{
    Q_OBJECT

public:
    explicit adminMenu(QWidget *parent = 0);
    ~adminMenu();

private slots:
    void on_pushButton_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

private:
    Ui::adminMenu *ui;
    list *fenetre3;
};

#endif // ADMINMENU_H

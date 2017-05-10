#include "adminmenu.h"
#include "ui_adminmenu.h"

adminMenu::adminMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminMenu)
{
    ui->setupUi(this);
}

adminMenu::~adminMenu()
{
    delete ui;
}

void adminMenu::on_pushButton_clicked()
{
    hide();
    fenetre3 = new list(this);
    fenetre3->show();
}

void adminMenu::on_lineEdit_textChanged(const QString &arg1)
{

}

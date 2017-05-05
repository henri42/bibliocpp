#ifndef ADMINMENU_H
#define ADMINMENU_H


#include<QApplication>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QBoxLayout>

class adminmenu : public QWidget
{
private:
    QHBoxLayout *layout;

    QPushButton* list;
    QPushButton* reset;
    QPushButton* load;
    QPushButton* save;
    QPushButton* add;
    QPushButton* del;

    QLineEdit* search;
public:
adminmenu();

signals:

public slots:

};

#endif // ADMINMENU_H

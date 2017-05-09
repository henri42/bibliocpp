#ifndef ADMINMENU_H
#define ADMINMENU_H


#include <QWidget>
#include <QPushButton>

namespace Ui {
class adminMenu;
}

class QPushButton;
class adminMenu : public QWidget
{
    Q_OBJECT

public:
    explicit adminMenu(QWidget *parent = 0);
    ~adminMenu();

private slots:
    void slotButtonClicked(bool checked);

private:
    Ui::adminMenu *ui;
    QPushButton *m_button;
};

#endif // ADMINMENU_H

#include "adminmenu.h"
#include "ui_adminmenu.h"

adminMenu::adminMenu(QWidget *parent) :
    QWidget(parent)
{
    // Create and position the button
    m_button = new QPushButton("Hello World", this);
    m_button->setGeometry(10, 10, 80, 30);
    m_button->setCheckable(true);

    connect(m_button, SIGNAL (clicked(bool)), this, SLOT (slotButtonClicked(bool)));
},
    ui(new Ui::adminMenu)
{
    ui->setupUi(this);
}

adminMenu::~adminMenu()
{
    delete ui;
}


void adminMenu::slotButtonClicked(bool checked)
{
    if (checked)
        m_button->setText("Checked");
    else
        m_button->setText("Hello World");
}

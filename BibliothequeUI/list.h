#ifndef LIST_H
#define LIST_H

#include <QDialog>

namespace Ui {
class list;
}

class list : public QDialog
{
    Q_OBJECT

public:
    explicit list(QWidget *parent = 0);
    ~list();

private:
    Ui::list *ui;
};

#endif // LIST_H

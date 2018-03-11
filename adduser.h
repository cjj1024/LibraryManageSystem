#ifndef ADDUSER_H
#define ADDUSER_H

#include <QWidget>
#include "user.h"

namespace Ui {
class AddUser;
}

class AddUser : public QWidget
{
    Q_OBJECT

public:
    explicit AddUser(User* node, User* node2, QWidget *parent = 0);
    ~AddUser();

    void closeEvent(QCloseEvent* e);

public slots:
    void AddUserSlot();

protected:
    User* user = NULL;
    User* addUser = NULL;

private:
    Ui::AddUser *ui;
};

#endif // ADDUSER_H

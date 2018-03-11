#ifndef DELETEUSER_H
#define DELETEUSER_H

#include "form.h"
#include "user.h"

class DeleteUser : public Form
{
    Q_OBJECT
public:
    DeleteUser(User* node, User* node2);

    void ShowAllUsers();
    void closeEvent(QCloseEvent* e);

public slots:
    void DeleteUserSlot();

protected:
    User* user = NULL;
    User* deleteUser = NULL;
};

#endif // DELETEUSER_H

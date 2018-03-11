#ifndef ADMININTERFACE_H
#define ADMININTERFACE_H

#include <QWidget>
#include "user.h"
#include "book.h"
#include "QTreeWidgetItem"

namespace Ui {
class AdminInterface;
}

class AdminInterface : public QWidget
{
    Q_OBJECT

public:
    explicit AdminInterface(QWidget *parent = 0);
    ~AdminInterface();

public slots:
    // 显示书的详细信息
    void ShowBookInfoSlot(QTreeWidgetItem* item, int column);
    // 添加书籍
    void AddBookSlot();
    // 删除书籍
    void DeleteBookSlot();
    // 添加用户
    void AddUserSlot();
    // 删除用户
    void DeleteUserSlot();

    // 显示所有的书籍信息
    void ShowAllBooks();
    // 显示所有用户的信息
    void ShowAllUsers();

private:
    Ui::AdminInterface *ui;

    // 储存所有的用户信息
    User* user = NULL;
    // 储存所有书的信息
    Book* book = NULL;
    // 储存添加的用户的信息
    User* addUser = NULL;
    // 储存删除的用户的信息
    User* deleteUser = NULL;
    // 储存添加的书信息
    Book* addBook = NULL;
    // 储存删除的书信息
    Book* deleteBook = NULL;
};

#endif // ADMININTERFACE_H

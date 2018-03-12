#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include <QWidget>
#include <QTreeWidget>
#include "book.h"
#include "userbook.h"

namespace Ui {
class UserInterface;
}

class UserInterface : public QWidget
{
    Q_OBJECT

public:
    explicit UserInterface(int id, QWidget *parent = 0);
    ~UserInterface();

public slots:
    // 打开借书界面的槽
    void BorrowBookSlot();
    // 打开还书界面的槽
    void ReturnBookSlot();
    // 显示书籍详细信息的槽
    void ShowBookInfoSlot(QTreeWidgetItem* item, int column);
    // 显示用户已借阅的书籍的槽
    void ShowAllUserBooks();

private:
    Ui::UserInterface *ui;

    UserBook* userBook = NULL;
    Book* book = NULL;
    UserBook* borrowBook = NULL;
    UserBook* returnBook = NULL;
};

#endif // USERINTERFACE_H

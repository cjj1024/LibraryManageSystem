#ifndef BORROWBOOK_H
#define BORROWBOOK_H

#include "form.h"
#include "book.h"
#include "userbook.h"

class BorrowBook : public Form
{
    Q_OBJECT
public:
    // node储存的是用户已借阅的书
    // node2用来储存当前操作借的书
    // node3储存所有书的信息
    BorrowBook(UserBook* node, UserBook* node2, Book* node3);

    // 拦截关闭事件
    void closeEvent(QCloseEvent* e);

    // 显示所有的书
    void ShowAllBooks();

public slots:
    // 当用户在借书界面点击确定按钮时，调用此函数
    void BorrowBookSlot();

protected:
    Book* book = NULL;
    UserBook* userBook = NULL;
    UserBook* borrowBook = NULL;
};

#endif // BORROWBOOK_H

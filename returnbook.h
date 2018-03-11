#ifndef RETURNBOOK_H
#define RETURNBOOK_H

#include "form.h"
#include "userbook.h"
#include "book.h"

class ReturnBook : public Form
{
    Q_OBJECT
public:
    ReturnBook(UserBook* node, UserBook* node2, Book* node3);

    void ShowAllUserBooks();
    void closeEvent(QCloseEvent* e);

public slots:
    void ReturnBookSlot();

protected:
    UserBook* userBook = NULL;
    UserBook* returnBook = NULL;
    Book* book = NULL;
};

#endif // RETURNBOOK_H

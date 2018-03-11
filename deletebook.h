#ifndef DELETEBOOK_H
#define DELETEBOOK_H

#include "form.h"
#include "book.h"

class DeleteBook : public Form
{
    Q_OBJECT
public:
    DeleteBook(Book* node, Book* node2);

    void ShowAllBooks();
    void closeEvent(QCloseEvent* e);

public slots:
    void DeleteBookSlot();

protected:
    Book* book = NULL;
    Book* deleteBook = NULL;
};

#endif // DELETEBOOK_H

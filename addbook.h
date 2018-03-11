#ifndef ADDBOOK_H
#define ADDBOOK_H

#include <QWidget>
#include "book.h"

namespace Ui {
class AddBook;
}

class AddBook : public QWidget
{
    Q_OBJECT

public:
    explicit AddBook(Book* node, Book* node2, QWidget *parent = 0);
    ~AddBook();

    void closeEvent(QCloseEvent* e);

public slots:
    void AddBookSlot();

protected:
    Book* book = NULL;
    Book* addBook = NULL;

private:
    Ui::AddBook *ui;
};

#endif // ADDBOOK_H

#ifndef BOOKINFO_H
#define BOOKINFO_H

#include <QWidget>
#include "nodetype.h"

namespace Ui {
class BookInfo;
}

class BookInfo : public QWidget
{
    Q_OBJECT

public:
    explicit BookInfo(BookType* node, QWidget *parent = 0);
    ~BookInfo();

private:
    Ui::BookInfo *ui;
};

#endif // BOOKINFO_H

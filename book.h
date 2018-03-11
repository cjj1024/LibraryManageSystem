#ifndef BOOK_H
#define BOOK_H

#include "linerlist.h"

class Book : public LinerList
{
public:
    Book();
    virtual ~Book();

    virtual void Init();
    virtual void SaveDelete();
    virtual void SaveAdd();
};

#endif // BOOK_H

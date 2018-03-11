#ifndef USERBOOK_H
#define USERBOOK_H

#include "linerlist.h"

class UserBook : public LinerList
{
public:
    UserBook(int id);
    virtual ~UserBook();

    virtual void Init();
    virtual void SaveAdd();
    virtual void SaveDelete();

public:
    int userId;
};

#endif // USERBOOK_H

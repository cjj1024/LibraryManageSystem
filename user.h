#ifndef USER_H
#define USER_H

#include "linerlist.h"

class User : public LinerList
{
public:
    User();
    virtual ~User();

    virtual void Init();
    virtual void SaveAdd();
    virtual void SaveDelete();
};

#endif // USER_H

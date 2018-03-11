#ifndef NODETYPE_H
#define NODETYPE_H

#include <QString>

//基类
class NodeType
{
public:
    // 通过id来判断是否是要找的节点
    virtual bool Compare(int id);

    int GetId();
    void SetId(int id);
    NodeType* GetNext();
    void SetNext(NodeType* node);

protected:
    int id;
    NodeType* next = NULL;
};

//用户类
class UserType : public NodeType
{
public:
    QString GetName();
    void SetName(QString name);
    QString GetPassword();
    void SetPassword(QString password);

protected:
    QString name;
    QString password;
};

//书类
class BookType : public NodeType
{
public:
    QString GetName();
    void SetName(QString name);
    QString GetAuthor();
    void SetAuthor(QString author);
    QString GetCategory();
    void SetCategory(QString category);
    QString GetIntroduction();
    void SetIntroduction(QString introduction);

protected:
    QString name;
    QString author;
    QString category;
    QString introduction;
};

// 用户的书类
class UserBookType : public NodeType
{
public:
    // 不是通过id来判断，而是bookId
    virtual bool Compare(int id);

    int GetBookId();
    void SetBookId(int id);
    int GetYear();
    void SetYear(int year);
    int GetMonth();
    void SetMonth(int month);
    int GetDay();
    void SetDay(int day);

protected:
    int bookId;
    int year;
    int month;
    int day;
};

#endif // NODETYPE_H

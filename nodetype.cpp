#include "nodetype.h"

int NodeType::GetId()
{
    return this->id;
}

void NodeType::SetId(int id)
{
    this->id = id;
}

NodeType* NodeType::GetNext()
{
    return this->next;
}

void NodeType::SetNext(NodeType *node)
{
    this->next = node;
}

QString UserType::GetName()
{
    return this->name;
}

void UserType::SetName(QString name)
{
    this->name = name;
}
QString UserType::GetPassword()
{
    return this->password;
}

void UserType::SetPassword(QString password)
{
    this->password = password;
}

bool NodeType::Compare(int id)
{
    if (this->id == id)
    {
        return true;
    }
    else
    {
        return false;
    }
}

QString BookType::GetName()
{
    return this->name;
}

void BookType::SetName(QString name)
{
    this->name = name;
}

QString BookType::GetAuthor()
{
    return this->author;
}

void BookType::SetAuthor(QString author)
{
    this->author = author;
}

QString BookType::GetCategory()
{
    return this->category;
}

void BookType::SetCategory(QString category)
{
    this->category = category;
}

QString BookType::GetIntroduction()
{
    return this->introduction;
}

void BookType::SetIntroduction(QString introduction)
{
    this->introduction = introduction;
}

int UserBookType::GetBookId()
{
    return this->bookId;
}

void UserBookType::SetBookId(int id)
{
    this->bookId = id;
}

int UserBookType::GetYear()
{
    return this->year;
}

void UserBookType::SetYear(int year)
{
    this->year = year;
}

int UserBookType::GetMonth()
{
    return this->month;
}

void UserBookType::SetMonth(int month)
{
    this->month = month;
}

int UserBookType::GetDay()
{
    return this->day;
}

void UserBookType::SetDay(int day)
{
    this->day = day;
}

bool UserBookType::Compare(int id)
{
    if (this->bookId == id)
    {
        return true;
    }
    else
    {
        return false;
    }
}

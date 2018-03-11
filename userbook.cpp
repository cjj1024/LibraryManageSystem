#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QDebug>
#include "userbook.h"

UserBook::UserBook(int id)
{
    this->userId = id;
}

UserBook::~UserBook()
{

}

void UserBook::Init()
{
    qDebug() << "Init UserBook" << endl;

    if (!this->db.open())
    {
        qDebug() << "Open Database UserBook Errors" << endl;
        return;
    }
    qDebug() << "Open Database UserBook Success" << endl;

    QSqlQuery query;
    QString statement;
    statement = QString("select * from userBooks where userId = %1;").arg(this->userId);
    qDebug() << statement << endl;
    query.exec(statement);
    this->length = query.size();
    while (query.next())
    {
        UserBookType* node = new UserBookType();
        node->SetId(query.value(0).toInt());
        node->SetBookId(query.value(1).toInt());
        node->SetYear(query.value(2).toInt());
        node->SetMonth(query.value(3).toInt());
        node->SetDay(query.value(4).toInt());
        this->AddNode(node);

//        qDebug() << node->id << " "
//                 << node->bookId << " "
//                 << node->year << " "
//                 << node->month << " "
//                 << node->day << endl;
    }

    this->db.close();
}

void UserBook::SaveAdd()
{
    qDebug() << "Save Add UserBook" << endl;

    if (!this->db.open())
    {
        qDebug() << "Open Database UserBook Errors" << endl;
        return;
    }
    qDebug() << "Open Database UserBook Success" << endl;

    UserBookType* node = (UserBookType*)this->list->GetNext();
    QSqlQuery query;
    QString statement;
    while (node != NULL)
    {
        statement = QString("insert into userBooks (userId, bookId, year, mouth, day)"
                            " values (%1, %2, %3, %4, %5);")
                .arg(node->GetId()).arg(node->GetBookId()).arg(node->GetYear())
                .arg(node->GetMonth()).arg(node->GetDay());
        qDebug() << statement << endl;
        query.exec(statement);

        node = (UserBookType*)node->GetNext();
    }

    this->db.close();
}

void UserBook::SaveDelete()
{
    qDebug() << "Save Delete UserBook" << endl;

    if (!this->db.open())
    {
        qDebug() << "Open Database UserBook Errors" << endl;
        return;
    }
    qDebug() << "Open Database UserBook Success" << endl;

    UserBookType* node = (UserBookType*)this->list->GetNext();
    QSqlQuery query;
    QString statement;
    while (node != NULL)
    {
        statement = QString("delete from userBooks where userId = %1"
                            " and bookId = %2;")
                .arg(node->GetId()).arg(node->GetBookId());
        qDebug() << statement << endl;
        query.exec(statement);

        node = (UserBookType*)node->GetNext();
    }

    this->db.close();
}

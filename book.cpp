#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QDebug>
#include "book.h"

Book::Book()
{

}

Book::~Book()
{

}

void Book::SaveAdd()
{
    qDebug() << "Save Add Book" << endl;
    if (!this->db.open())
    {
        qDebug() << "Open Book Database Error" << endl;
    }
    qDebug() << "Open Book Database Success" << endl;

    QString statement;
    QSqlQuery query;
    BookType* node = (BookType*)this->list->GetNext();
    while (node != NULL)
    {
        statement = QString("insert into books (id, name, author, category,"
                            " introduction) values (%1, '%2', '%3', '%4','%5');")
                .arg(node->GetId()).arg(node->GetName()).arg(node->GetAuthor())
                .arg(node->GetCategory()).arg(node->GetIntroduction());
        qDebug() << statement << endl;
        query.exec(statement);

        node = (BookType*)node->GetNext();
    }

    this->db.close();
}

void Book::SaveDelete()
{
    qDebug() << "Save Delete Book" << endl;
    if (!this->db.open())
    {
        qDebug() << "Open Book Database Error" << endl;
        return;
    }
    qDebug() << "Open Book Database Success" << endl;

    QString statement;
    BookType* node = (BookType*)this->list->GetNext();
    QSqlQuery query;
    while (node != NULL)
    {
        statement = QString("delete from books where id = %1;").arg(node->GetId());
        qDebug() << statement << endl;
        query.exec(statement);
        node = (BookType*)node->GetNext();
    }

    this->db.close();
}

void Book::Init()
{
    qDebug() << "Init Book" << endl;

    if (!this->db.open())
    {
        qDebug() << "Open Book Database Error" << endl;
        return;
    }
    qDebug() << "Open Book Database Success" << endl;

    QSqlQuery query;
    query.exec("select * from books");
    this->length = query.size();
    while (query.next())
    {
        BookType* node = new BookType();
        node->SetId(query.value(0).toInt());
        node->SetName(query.value(1).toString());
        node->SetAuthor(query.value(2).toString());
        node->SetCategory(query.value(3).toString());
        node->SetIntroduction(query.value(4).toString());
        this->AddNode(node);

//        qDebug() << node->id << " "
//                 << node->name << " "
//                 << node->author << " "
//                 << node->category << " "
//                 << node->introduction << endl;
    }

    this->db.close();
}


#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QDebug>
#include "user.h"

User::User()
{

}

User::~User()
{

}

void User::Init()
{
    qDebug() << "Init User" << endl;

    // 打开数据库，如果失败就退出
    if (!this->db.open())
    {
        qDebug() << "Open User Database Error" << endl;
        return;
    }
    qDebug() << "Open User Database Success" << endl;

    // 该类提供了一些执行MySql语句函数
    // 同时也保存了执行的结果
    QSqlQuery query;

    // 执行MySql语句，从查询users表中所有信息
    query.exec("select * from users");
    // 查询到多少条信息就表示有多少个用户
    this->length = query.size();
    // next函数使query指向下一条记录
    // 成功返回true，失败返回false
    while (query.next())
    {
        UserType* node = new UserType();
        // value函数获得query指向的记录的第n个属性
        node->SetId(query.value(0).toInt());
        node->SetName(query.value(1).toString());
        node->SetPassword(query.value(2).toString());
        this->AddNode(node);

        qDebug() << node->GetId() << " "
                 << node->GetName() << " "
                 << node->GetPassword() << endl;
    }

    //关闭数据库
    this->db.close();
}

void User::SaveAdd()
{
    qDebug() << "Save Add User" << endl;
    if (!this->db.open())
    {
        qDebug() << "Open User Database Error" << endl;
    }
    qDebug() << "Open User Database Success" << endl;

    QString statement;
    QSqlQuery query;
    UserType* node = (UserType*)this->list->GetNext();
    while (node != NULL)
    {
        // arg函数提供格式化字符串，用来代替字符串中的占位符%1，%2等等
        statement = QString("insert into users (id, name, password) values "
                            "(%1, '%2', '%3');")
                .arg(node->GetId()).arg(node->GetName()).arg(node->GetPassword());
        qDebug() << statement << endl;
        // 执行MySql语句，向users表中添加一条记录
        query.exec(statement);

        node = (UserType*)node->GetNext();
    }

    this->db.close();
}

void User::SaveDelete()
{
    qDebug() << "Save Delete User" << endl;
    if (!this->db.open())
    {
        qDebug() << "Open User Database Error" << endl;
    }
    qDebug() << "Open User Database Success" << endl;

    QString statement;
    QSqlQuery query;
    UserType* node = (UserType*)this->list->GetNext();
    while (node != NULL)
    {
        statement = QString("delete from users where id = %1;").arg(node->GetId());
        qDebug() << statement << endl;
        // 执行MySql语句，从users表中删除一条记录
        query.exec(statement);
        node = (UserType*)node->GetNext();
    }

    this->db.close();
}



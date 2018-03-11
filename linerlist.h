#ifndef LINERLIST_H
#define LINERLIST_H

#include <QtSql/QSqlDatabase>
#include "nodetype.h"

class LinerList
{
public:
    LinerList();
    virtual ~LinerList();

    // 从文件中读取信息来初始化链表
    virtual void Init();
    // 清空整个链表
    virtual void Clear();
    // 把链表中的信息保存下来，使用第一个节点，也就是头节点的id来标记是删除还是添加
    // id为1时，向文件中添加链表中的节点信息
    // id为-1时，把链表中的节点信息从文件中删除
    virtual void Save();
    // 向文件中添加链表中的节点信息
    virtual void SaveAdd();
    // 从文件中把链表中的节点信息删除
    virtual void SaveDelete();
    // 向链表中添加一个节点，node为空时无操作
    virtual void AddNode(NodeType* node);
    // 从链表中删除属性为id的节点
    virtual void DeleteNode(int id);
    // 获得属性为id的节点，id为-1时，获得头节点，其它返回空
    virtual NodeType* GetNode(int id);

protected:
    static QSqlDatabase db;
    NodeType* list = NULL;
    int length = 0;
};

#endif // LINERLIST_H

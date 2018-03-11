#include "linerlist.h"

//初始化数据库对象
QSqlDatabase LinerList::db = QSqlDatabase::addDatabase("QMYSQL");

LinerList::LinerList()
{
    //头节点
    this->list = new NodeType();
    this->list->SetNext(NULL);

    //初始化数据库信息
    this->db.setDatabaseName("LibraryManageSystem");
    this->db.setHostName("localhost");
    this->db.setUserName("user");
    this->db.setPort(3306);
    this->db.setPassword("123456");
}

LinerList::~LinerList()
{
    NodeType* preNode = this->list;
    NodeType* nextNode = this->list;

    while (nextNode != NULL)
    {
        preNode = nextNode;
        nextNode = nextNode->GetNext();

        delete preNode;
    }

    this->list = NULL;
}

void LinerList::Clear()
{
    NodeType* preNode = this->list->GetNext();
    NodeType* nextNode = this->list->GetNext();

    while (nextNode != NULL)
    {
        preNode = nextNode;
        nextNode = nextNode->GetNext();

        delete preNode;
    }

    this->length = 0;
    this->list->SetNext(NULL);
}

NodeType* LinerList::GetNode(int id)
{
    // 当id为-1时，返回头节点
    if (id == -1)
    {
        return this->list;
    }

    NodeType* node = this->list->GetNext();
    while (node != NULL)
    {
        if (node->GetId() == id)
        {
            return node;
        }

        node = node->GetNext();
    }

    return NULL;
}

void LinerList::AddNode(NodeType *node)
{
    if (node == NULL)
    {
        return;
    }

    node->SetNext(this->list->GetNext());
    this->list->SetNext(node);
    this->length++;
}

void LinerList::DeleteNode(int id)
{
    NodeType* preNode = this->list;
    NodeType* nextNode = this->list->GetNext();

    while (nextNode != NULL)
    {
        if (nextNode->Compare(id))
        {
            preNode->SetNext(nextNode->GetNext());
            delete nextNode;
            this->length--;
            break;
        }
        else
        {
            preNode = nextNode;
            nextNode = nextNode->GetNext();
        }

    }
}

// LinerList只是基类，没有要初始化的信息
// 初始化的具体实现在每一个子类中实现
void LinerList::Init()
{

}

void LinerList::Save()
{
    NodeType* node = this->GetNode(-1);
    // 当头节点id为1时，表示把链表中的信息添加到数据库中
    // 当有节点id为-1时，表示把链表中的信息从数据库中删掉
    if (node->GetId() == 1)
    {
        this->SaveAdd();
    }
    else if (node->GetId() == -1)
    {
        this->SaveDelete();
    }
}

// 在子类中具体实现
void LinerList::SaveAdd()
{

}

// 在子类中具体实现
void LinerList::SaveDelete()
{

}

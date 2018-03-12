#include <QDebug>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QDate>
#include "userinterface.h"
#include "ui_userinterface.h"
#include "bookinfo.h"
#include "borrowbook.h"
#include "returnbook.h"

UserInterface::UserInterface(int id, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserInterface)
{
    ui->setupUi(this);
    this->setWindowTitle(QString::fromLocal8Bit("用户"));

    // 登录后，把登陆的用户的id传过来，
    // 根据id创建一个用户
    this->userBook = new UserBook(id);
    this->userBook->Init();
    // 储存的是数据库中所有的书籍信息
    this->book = new Book();
    this->book->Init();
    // 用户在借书界面借的书会储存在borrowBook里，
    // 头节点设为1表示链表中的节点要添加到数据库中
    this->borrowBook = new UserBook(this->userBook->userId);
    this->borrowBook->GetNode(-1)->SetId(1);
    // 用户在还书界面还的书会储存在returnBook里
    // 头节点设为-1表示链表中的节点要从数据库中删去
    this->returnBook = new UserBook(this->userBook->userId);
    this->returnBook->GetNode(-1)->SetId(-1);

    // 当用户双击书籍时，会显示书籍的详细信息
    QObject::connect(ui->treeWidget, SIGNAL(itemDoubleClicked(QTreeWidgetItem*,int)), this,
                     SLOT(ShowBookInfoSlot(QTreeWidgetItem*, int)));
    // 当用户点击借书按钮，会打开借书界面
    QObject::connect(ui->borrowPushButton, SIGNAL(clicked(bool)),
                     this, SLOT(BorrowBookSlot()));
    // 当用户点击还书按钮，会打开还书界面
    QObject::connect(ui->returnPushButton, SIGNAL(clicked(bool)),
                     this, SLOT(ReturnBookSlot()));
}

UserInterface::~UserInterface()
{
    delete ui;

    if (this->userBook != NULL)
    {
        delete this->userBook;
        this->userBook = NULL;
    }

    if (this->book != NULL)
    {
        delete this->book;
        this->book = NULL;
    }

    if (this->borrowBook != NULL)
    {
        delete this->borrowBook;
        this->borrowBook = NULL;
    }

    if (this->returnBook != NULL)
    {
        delete this->returnBook;
        this->returnBook = NULL;
    }
}

void UserInterface::ShowAllUserBooks()
{
    // 清空treeWidget
    ui->treeWidget->clear();

    // 获得头节点
    UserBookType* node = (UserBookType*)this->userBook->GetNode(-1);
    // 获得第一个节点
    node = (UserBookType*)node->GetNext();
    // 循环整个链表
    while (node != NULL)
    {
        // 根据书籍id获得该书的节点
        BookType* bookNode = (BookType*)this->book->GetNode(node->GetBookId());
        // QTreeWidgetItem是Tree Widget的一行
        QTreeWidgetItem* item = new QTreeWidgetItem();
        // 设置每一行各个项的值
        item->setText(0, QString::number(node->GetBookId()));
        item->setText(1, bookNode->GetName());
        item->setText(2, bookNode->GetAuthor());
        item->setText(3, bookNode->GetAuthor());
        item->setText(4, QString("%1-%2-%3")
                      .arg(node->GetYear())
                      .arg(node->GetMonth())
                      .arg(node->GetDay()));
        // 书的借阅时间是六个月，当前日期加6个月就是还书日期
        QDate date(node->GetYear(), node->GetMonth(), node->GetDay());
        date.addMonths(6);
        item->setText(5, QString("%1-%2-%3")
                      .arg(date.year())
                      .arg(date.month())
                      .arg(date.day()));
        // 把QTreeWidgetItem插入Tree Widget
        ui->treeWidget->insertTopLevelItem(0, item);

        node = (UserBookType*)node->GetNext();
    }
}

// 打开显示书本详细信息的界面
void UserInterface::ShowBookInfoSlot(QTreeWidgetItem *item, int column)
{
    BookType* node = (BookType*)this->book->GetNode(item->text(0).toInt());
    BookInfo* w = new BookInfo(node);
    w->show();
}

// 打开借书界面
void UserInterface::BorrowBookSlot()
{
    BorrowBook* w = new BorrowBook(this->userBook, this->borrowBook, this->book);
    // 设置当close时销毁，发出destoryed信号
    w->setAttribute(Qt::WA_DeleteOnClose);
    // 当收到借书界面的destroyed信号时，调用ShowAllUserBooks函数
    QWidget::connect(w, SIGNAL(destroyed()), this, SLOT(ShowAllUserBooks()));
    w->show();
    w->ShowAllBooks();
}

// 打开还书界面
void UserInterface::ReturnBookSlot()
{
    ReturnBook* w = new ReturnBook(this->userBook, this->returnBook, this->book);
    // 设置当close时销毁，发出destoryed信号
    w->setAttribute(Qt::WA_DeleteOnClose);
    // 当收到借书界面的destroyed信号时，调用ShowAllUserBooks函数
    QWidget::connect(w, SIGNAL(destroyed()), this, SLOT(ShowAllUserBooks()));
    w->show();
    w->ShowAllUserBooks();
}

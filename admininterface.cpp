#include "admininterface.h"
#include "ui_admininterface.h"
#include "bookinfo.h"
#include "addbook.h"
#include "deletebook.h"
#include "adduser.h"
#include "deleteuser.h"

AdminInterface::AdminInterface(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AdminInterface)
{
    ui->setupUi(this);
    this->setWindowTitle(QString::fromLocal8Bit("管理员界面"));
    // 设置两个tab的标题
    ui->tabWidget->setTabText(0, QString::fromLocal8Bit("书籍管理"));
    ui->tabWidget->setTabText(1, QString::fromLocal8Bit("用户管理"));

    this->book = new Book();
    this->book->Init();
    this->user = new User();
    this->user->Init();

    // 链表头节点的id值表示添加或删除
    // 1表示把链表中的信息添加到数据库中
    // -1表示把链表中的信息从数据库中删掉
    this->addBook = new Book();
    this->addBook->GetNode(-1)->SetId(1);
    this->deleteBook = new Book();
    this->deleteBook->GetNode(-1)->SetId(-1);
    this->addUser = new User();
    this->addUser->GetNode(-1)->SetId(1);
    this->deleteUser = new User();
    this->deleteUser->GetNode(-1)->SetId(-1);

    // 双击book Tree Widget 的每一行，会显示书的详细信息
    QObject::connect(ui->bookTreeWidget, SIGNAL(itemDoubleClicked(QTreeWidgetItem*,int)),
                     this, SLOT(ShowBookInfoSlot(QTreeWidgetItem*,int)));
    // 点击添加书籍按钮，会进入添加书籍的界面
    QObject::connect(ui->addBookPushButton, SIGNAL(clicked(bool)),
                     this, SLOT(AddBookSlot()));
    // 点击删除书籍按钮，会进入删除书籍的界面
    QObject::connect(ui->deleteBookPushButton, SIGNAL(clicked(bool)),
                     this, SLOT(DeleteBookSlot()));
    // 点击添加用户按钮，会进入添加用户的界面
    QObject::connect(ui->addUserPushButton, SIGNAL(clicked(bool)),
                     this, SLOT(AddUserSlot()));
    // 点击删除用户按钮，会进入删除用户的界面
    QObject::connect(ui->deleteUserPushButton, SIGNAL(clicked(bool)),
                     this, SLOT(DeleteUserSlot()));
}

AdminInterface::~AdminInterface()
{
    delete ui;

    if (this->book != NULL)
    {
        delete this->book;
        this->book = NULL;
    }

    if (this->user != NULL)
    {
        delete this->user;
        this->user = NULL;
    }

    if (this->addBook != NULL)
    {
        delete this->addBook;
        this->addBook = NULL;
    }

    if (this->addUser != NULL)
    {
        delete this->addUser;
        this->addUser = NULL;
    }

    if (this->deleteBook != NULL)
    {
        delete this->deleteBook;
        this->deleteBook = NULL;
    }

    if (this->deleteUser != NULL)
    {
        delete this->deleteUser;
        this->deleteUser = NULL;
    }
}

void AdminInterface::ShowBookInfoSlot(QTreeWidgetItem *item, int column)
{
    BookType* node = (BookType*)this->book->GetNode(item->text(0).toInt());
    BookInfo* w = new BookInfo(node);
    w->show();
}

void AdminInterface::ShowAllBooks()
{
    if (this->book == NULL)
    {
        return;
    }

    ui->bookTreeWidget->clear();

    BookType* node = (BookType*)this->book->GetNode(-1);
    node = (BookType*)node->GetNext();
    while (node != NULL)
    {
        QTreeWidgetItem* item = new QTreeWidgetItem();
        item->setText(0, QString::number(node->GetId()));
        item->setText(1, node->GetName());
        item->setText(2, node->GetAuthor());
        item->setText(3, node->GetCategory());
        ui->bookTreeWidget->insertTopLevelItem(0, item);

        node = (BookType*)node->GetNext();
    }
}

void AdminInterface::ShowAllUsers()
{
    if (this->user == NULL)
    {
        return;
    }

    ui->userTreeWidget->clear();

    UserType* node = (UserType*)this->user->GetNode(-1);
    node = (UserType*)node->GetNext();
    while (node != NULL)
    {
        QTreeWidgetItem* item = new QTreeWidgetItem();
        item->setText(0, QString::number(node->GetId()));
        item->setText(1, node->GetName());
        item->setText(2, node->GetPassword());
        ui->userTreeWidget->insertTopLevelItem(0, item);

        node = (UserType*)node->GetNext();
    }
}

void AdminInterface::AddBookSlot()
{
    AddBook* w = new AddBook(this->book, this->addBook);
    // 设置当AddBook界面关闭后自动销毁
    // 界面销毁时会产生destroyed信号
    // 当管理员界面收到destroyed信号时，重新显示书籍
    w->setAttribute(Qt::WA_DeleteOnClose);
    QObject::connect(w, SIGNAL(destroyed()), this, SLOT(ShowAllBooks()));
    w->show();
}

void AdminInterface::DeleteBookSlot()
{
    DeleteBook* w = new DeleteBook(this->book, this->deleteBook);
    // 设置当DeleteBook界面关闭后自动销毁
    // 界面销毁时会产生destroyed信号
    // 当管理员界面收到destroyed信号时，重新显示书籍
    w->setAttribute(Qt::WA_DeleteOnClose);
    QObject::connect(w, SIGNAL(destroyed()), this, SLOT(ShowAllBooks()));
    w->show();
    // 显示所有书籍
    w->ShowAllBooks();
}

void AdminInterface::AddUserSlot()
{
    AddUser* w = new AddUser(this->user, this->addUser);
    // 设置当AddUser界面关闭后自动销毁
    // 界面销毁时会产生destroyed信号
    // 当管理员界面收到destroyed信号时，重新显示用户
    w->setAttribute(Qt::WA_DeleteOnClose);
    QObject::connect(w, SIGNAL(destroyed()), this, SLOT(ShowAllUsers()));
    w->show();
}

void AdminInterface::DeleteUserSlot()
{
    DeleteUser* w = new DeleteUser(this->user, this->deleteUser);
    // 设置当AddUser界面关闭后自动销毁
    // 界面销毁时会产生destroyed信号
    // 当管理员界面收到destroyed信号时，重新显示用户
    w->setAttribute(Qt::WA_DeleteOnClose);
    QObject::connect(w, SIGNAL(destroyed()), this, SLOT(ShowAllUsers()));
    w->show();
    w->ShowAllUsers();
}

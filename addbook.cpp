#include <QMessageBox>
#include "addbook.h"
#include "ui_addbook.h"

AddBook::AddBook(Book *node, Book *node2, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddBook)
{
    ui->setupUi(this);
    this->setWindowTitle(QString::fromLocal8Bit("添加书籍"));

    this->book = node;
    this->addBook = node2;

    QObject::connect(ui->confirmPushButton, SIGNAL(clicked()),
                     this, SLOT(AddBookSlot()));
    QObject::connect(ui->cancelPushButton, SIGNAL(clicked()),
                     this, SLOT(close()));
}

AddBook::~AddBook()
{
    delete ui;
}

void AddBook::closeEvent(QCloseEvent *e)
{
    // 弹出对话框，询问是否保存
    QMessageBox::StandardButton msg = QMessageBox::information(this,
              tr("Prompt"),
              tr("Save You Operation?"),
              QMessageBox::Save,
              QMessageBox::Cancel);

    switch (msg)
    {
    case QMessageBox::Save:
    {
        // 把添加的书添加到book中
        BookType* node = (BookType*)this->addBook->GetNode(-1);
        node = (BookType*)node->GetNext();
        while (node != NULL)
        {
            BookType* node2 = new BookType();
            node2->SetId(node->GetId());
            node2->SetName(node->GetName());
            node2->SetAuthor(node->GetAuthor());
            node2->SetCategory(node->GetCategory());
            node2->SetIntroduction(node->GetIntroduction());
            this->book->AddNode(node2);

            node = (BookType*)node->GetNext();
        }
        // 把添加的书保存到数据库中
        this->addBook->Save();
    } break;
    case QMessageBox::Cancel:
    {
        // 清空添加的书
        this->addBook->Clear();
    } break;
    default:
        break;
    }
}

void AddBook::AddBookSlot()
{
    // 判断用户是否有输入
    // 这里只判断了用户是否输入了书的id
    // isModified函数判断LineEdit是否被修改
    if (!ui->idLineEdit->isModified())
    {
        return;
    }

    // 根据用户输入的信息新建一个书
    // 并插入到addBook链表中
    BookType* node = new BookType();
    node->SetId(ui->idLineEdit->text().toInt());
    node->SetName(ui->nameLineEdit->text());
    node->SetAuthor(ui->authorLineEdit->text());
    node->SetCategory(ui->categoryLineEdit->text());
    node->SetIntroduction(ui->introductionTextEdit->toPlainText());

    this->addBook->AddNode(node);

    this->close();
}

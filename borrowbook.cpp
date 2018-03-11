#include <QDate>
#include <QDebug>
#include <QMessageBox>
#include "borrowbook.h"
#include "ui_form.h"

BorrowBook::BorrowBook(UserBook* node, UserBook* node2, Book* node3)
{
    this->setWindowTitle(QString::fromLocal8Bit("借书"));
    // 为Tree Widget设置有多少列，并设置每一列的名称
    // 设置Tree Widget共四列
    ui->treeWidget->setColumnCount(4);
    QStringList header;
    header << QString::fromLocal8Bit("书籍编号")
           << QString::fromLocal8Bit("书籍名称")
           << QString::fromLocal8Bit("书籍作者")
           << QString::fromLocal8Bit("书籍类型");
    // 设置Tree Widget每一列的标题
    ui->treeWidget->setHeaderLabels(header);

    this->userBook = node;
    this->borrowBook = node2;
    this->book = node3;

    // 把确定按钮与借书操作连接起来
    QObject::connect(ui->confirmPushButton, SIGNAL(clicked()),
                     this, SLOT(BorrowBookSlot()));
}

// 关闭事件处理程序
void BorrowBook::closeEvent(QCloseEvent *)
{
    // 弹出对话框，询问是否保存
    QMessageBox::StandardButton msg = QMessageBox::information(this,
              tr("Prompt"),
              tr("Save You Book?"),
              QMessageBox::Save,
              QMessageBox::Cancel);

    switch (msg)
    {
    case QMessageBox::Save:
    {
        // 把借的书添加到userBook链表中
        UserBookType* node = (UserBookType*)this->borrowBook->GetNode(-1);
        node = (UserBookType*)node->GetNext();
        while (node != NULL)
        {
            UserBookType* node2 = new UserBookType();
            node2->SetId(node->GetId());
            node2->SetBookId(node->GetBookId());
            node2->SetYear(node->GetYear());
            node2->SetMonth(node->GetMonth());
            node2->SetDay(node->GetDay());
            this->userBook->AddNode(node2);
            node = (UserBookType*)node->GetNext();
        }

        // 把borrowBook链表中的信息添加到数据库中
        this->borrowBook->Save();
    } break;
    case QMessageBox::Cancel:
    {
        this->borrowBook->Clear();
    } break;
    default:
        break;
    }
}

void BorrowBook::BorrowBookSlot()
{
    // 遍历Tree Widget的每一行
    // topLevelItemCount函数用于获得Tree Widget有多少行
    for (int i = 0; i < ui->treeWidget->topLevelItemCount(); i++)
    {
        QTreeWidgetItem* item = ui->treeWidget->topLevelItem(i);
        // 判断改行的复选框是否被选中
        // 如果选中，就添加到userBook，borrowBook中
        if (item->checkState(0) == Qt::Checked)
        {
            UserBookType* node = new UserBookType();
            node->SetId(this->userBook->userId);
            node->SetBookId(item->text(0).toInt());
            QDate date;
            date = date.currentDate();
            qDebug() << date.year() << " " << date.month() << " " << endl;
            node->SetYear(date.year());
            node->SetMonth(date.month());
            node->SetDay(date.day());
            this->borrowBook->AddNode(node);

            // 把复选框置回到未选中的状态
            item->setCheckState(0, Qt::Unchecked);
        }
    }
    this->close();
}


void BorrowBook::ShowAllBooks()
{
    if (this->book == NULL)
    {
        return;
    }

    // 获得头节点
    BookType* node = (BookType*)this->book->GetNode(-1);
    // 获得第一个节点
    node = (BookType*)node->GetNext();
    // 遍历整个链表，把所有book的信息显示到Tree Widget上
    while (node != NULL)
    {
        QTreeWidgetItem* item = new QTreeWidgetItem();
        item->setText(0, QString::number(node->GetId()));
        item->setText(1, node->GetName());
        item->setText(2, node->GetAuthor());
        item->setText(3, node->GetCategory());
        // 设置item的标志
        // ItemIsEnabled设置item可用
        // ItemIsSelectable设置item可选
        // ItemIsUserCheckable设置item有复选框
        item->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable
                       | Qt::ItemIsUserCheckable);
        // 设置item的初始状态
        // 第一个参数表示要设置哪一列
        // 第二个参数设置初始状态，我们设置为未选中
        item->setCheckState(0, Qt::Unchecked);
        // 把item添加到Tree Widget中
        ui->treeWidget->insertTopLevelItem(0, item);

        node = (BookType*)node->GetNext();
    }
}

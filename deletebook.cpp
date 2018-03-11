#include <QMessageBox>
#include "deletebook.h"
#include "ui_form.h"

DeleteBook::DeleteBook(Book *node, Book *node2)
{
    this->setWindowTitle(QString::fromLocal8Bit("删除书籍"));
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

    this->book = node;
    this->deleteBook = node2;

    QObject::connect(ui->confirmPushButton, SIGNAL(clicked()),
                     this, SLOT(DeleteBookSlot()));
}

void DeleteBook::ShowAllBooks()
{
    if (this->book == NULL)
    {
        return;
    }

    // 遍历book链表
    BookType* node = (BookType*)this->book->GetNode(-1);
    node = (BookType*)node->GetNext();
    while (node != NULL)
    {
        QTreeWidgetItem* item = new QTreeWidgetItem();
        item->setText(0, QString::number(node->GetId()));
        item->setText(1, node->GetName());
        item->setText(2, node->GetAuthor());
        item->setText(3, node->GetCategory());
        // 设置第0项有复选框
        item->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable
                       | Qt::ItemIsUserCheckable);
        item->setCheckState(0, Qt::Unchecked);
        ui->treeWidget->insertTopLevelItem(0, item);

        node = (BookType*)node->GetNext();
    }
}

void DeleteBook::closeEvent(QCloseEvent *e)
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
        // 把删掉的书从book链表中删掉
        BookType* node = (BookType*)this->deleteBook->GetNode(-1);
        node = (BookType*)node->GetNext();
        while (node != NULL)
        {
            this->book->DeleteNode(node->GetId());
            node = (BookType*)node->GetNext();
        }
        // 把删掉的书从数据库中删掉
        this->deleteBook->Save();
    } break;
    case QMessageBox::Cancel:
    {
        // 用户不保存删除操作
        this->deleteBook->Clear();
    } break;
    default:
        break;
    }
}

void DeleteBook::DeleteBookSlot()
{
    // 遍历Tree Widget查看每一行的复选框是否被选中
    // 选中了则添加进deleteBook链表
    // 删除书籍只需要记录书的id
    for (int i = 0; i < ui->treeWidget->topLevelItemCount(); i++)
    {
        QTreeWidgetItem* item = ui->treeWidget->topLevelItem(i);
        if (item->checkState(0) == Qt::Checked)
        {
            BookType* node = new BookType();
            node->SetId(item->text(0).toInt());
            this->deleteBook->AddNode(node);

            // 把复选框置回未选中状态
            item->setCheckState(0, Qt::Unchecked);
        }
    }

    this->close();
}


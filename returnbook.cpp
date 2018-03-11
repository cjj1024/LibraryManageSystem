#include <QMessageBox>
#include "returnbook.h"
#include "ui_form.h"

ReturnBook::ReturnBook(UserBook *node, UserBook *node2, Book *node3)
{
    this->setWindowTitle(QString::fromLocal8Bit("借书"));
    ui->treeWidget->setColumnCount(4);
    QStringList header;
    header << QString::fromLocal8Bit("书籍编号")
           << QString::fromLocal8Bit("书籍名称")
           << QString::fromLocal8Bit("书籍作者")
           << QString::fromLocal8Bit("书籍类型");
    ui->treeWidget->setHeaderLabels(header);

    this->userBook = node;
    this->returnBook = node2;
    this->book = node3;

    QWidget::connect(ui->confirmPushButton, SIGNAL(clicked()),
                     this, SLOT(ReturnBookSlot()));
}

void ReturnBook::ShowAllUserBooks()
{
    if (this->book == NULL || this->userBook == NULL)
    {
        return;
    }

    UserBookType* node = (UserBookType*)this->userBook->GetNode(-1);
    node = (UserBookType*)node->GetNext();
    while (node != NULL)
    {
        // 根据书的id获得书的具体信息
        BookType* node2 = (BookType*)this->book->GetNode(node->GetBookId());
        QTreeWidgetItem* item = new QTreeWidgetItem();
        item->setText(0, QString::number(node2->GetId()));
        item->setText(1, node2->GetName());
        item->setText(2, node2->GetAuthor());
        item->setText(3, node2->GetCategory());
        item->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable
                       | Qt::ItemIsUserCheckable);
        item->setCheckState(0, Qt::Unchecked);

        ui->treeWidget->insertTopLevelItem(0, item);

        node = (UserBookType*)node->GetNext();
    }
}

void ReturnBook::ReturnBookSlot()
{
    for (int i = 0; i < ui->treeWidget->topLevelItemCount(); i++)
    {
        QTreeWidgetItem* item = ui->treeWidget->topLevelItem(i);
        if (item->checkState(0) == Qt::Checked)
        {
            UserBookType* node = new UserBookType();
            // 删除一本书只要人的id和书的id，其他信息并不需要
            node->SetId(this->userBook->userId);
            node->SetBookId(item->text(0).toInt());
            this->returnBook->AddNode(node);

            item->setCheckState(0, Qt::Unchecked);
      }
    }
    this->close();
}

void ReturnBook::closeEvent(QCloseEvent *e)
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
        UserBookType* node = (UserBookType*)this->returnBook->GetNode(-1);
        node = (UserBookType*)node->GetNext();
        while (node != NULL)
        {
            // 根据书的id从userBook链表中删除还的书
            this->userBook->DeleteNode(node->GetBookId());
            node = (UserBookType*)node->GetNext();
        }

        // 把returnBook链表中的信息从数据库中删掉
        this->returnBook->Save();
    } break;
    case QMessageBox::Cancel:
    {
        // 清空returBook链表
        this->returnBook->Clear();
    } break;
    default:
        break;
    }
}

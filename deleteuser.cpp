#include <QMessageBox>
#include "deleteuser.h"
#include "ui_form.h"

DeleteUser::DeleteUser(User *node, User *node2)
{
    this->setWindowTitle(QString::fromLocal8Bit("删除用户"));
    // 在Tree Widget上需要显示四列信息
    ui->treeWidget->setColumnCount(4);
    QStringList header;
    header << QString::fromLocal8Bit("书籍编号")
           << QString::fromLocal8Bit("书籍名称")
           << QString::fromLocal8Bit("书籍作者")
           << QString::fromLocal8Bit("书籍类型");
    ui->treeWidget->setHeaderLabels(header);

    this->user = node;
    this->deleteUser = node2;

    // 当用户点击确认按钮后，开始进行删除操作
    QObject::connect(ui->confirmPushButton, SIGNAL(clicked()),
                     this, SLOT(DeleteUserSlot()));
}

void DeleteUser::closeEvent(QCloseEvent *e)
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
        UserType* node = (UserType*)this->deleteUser->GetNode(-1);
        node = (UserType*)node->GetNext();
        while (node != NULL)
        {
            this->user->DeleteNode(node->GetId());

            node = (UserType*)node->GetNext();
        }
        // 把删掉的书从数据库中删掉
        this->deleteUser->Save();
    } break;
    case QMessageBox::Cancel:
    {
        // 用户不保存删除操作
        this->deleteUser->Clear();
    } break;
    default:
        break;
    }
}

void DeleteUser::DeleteUserSlot()
{
    // 遍历Tree Widget的每一行，判断复选框是否被选中
    // 如果被选中，把它添加到deleteUser链表中，方便后续操作
    // 复选框要置回位选中状态
    for (int i = 0; i < ui->treeWidget->topLevelItemCount(); i++)
    {
        QTreeWidgetItem* item = ui->treeWidget->topLevelItem(i);
        if (item->checkState(0) == Qt::Checked)
        {
            UserType* node = new UserType();
            node->SetId(item->text(0).toInt());
            this->deleteUser->AddNode(node);

            item->setCheckState(0, Qt::Unchecked);
        }
    }

    this->close();
}

void DeleteUser::ShowAllUsers()
{
    if (this->user == NULL)
    {
        return;
    }

    // 循环user链表，把所有用户的信息显示在Tree Widget中
    // 每一行，在第0项会设置一个复选框
    UserType* node = (UserType*)this->user->GetNode(-1);
    node = (UserType*)node->GetNext();
    while (node != NULL)
    {
        QTreeWidgetItem* item = new QTreeWidgetItem();
        item->setText(0, QString::number(node->GetId()));
        item->setText(1, node->GetName());
        item->setText(2, node->GetPassword());
        item->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable
                       | Qt::ItemIsUserCheckable);
        item->setCheckState(0, Qt::Unchecked);
        ui->treeWidget->insertTopLevelItem(0, item);

        node = (UserType*)node->GetNext();
    }
}

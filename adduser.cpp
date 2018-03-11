#include <QMessageBox>
#include "adduser.h"
#include "ui_adduser.h"

AddUser::AddUser(User *node, User *node2, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddUser)
{
    ui->setupUi(this);    
    this->setWindowTitle(QString::fromLocal8Bit("添加用户"));

    this->user = node;
    this->addUser = node2;

    QObject::connect(ui->confirmPushButton, SIGNAL(clicked()),
                     this, SLOT(AddUserSlot()));
    QObject::connect(ui->cancelPushButton, SIGNAL(clicked()),
                     this, SLOT(close()));
}

AddUser::~AddUser()
{
    delete ui;
}

void AddUser::closeEvent(QCloseEvent *e)
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
        // 把添加的用户添加到user中
        UserType* node = (UserType*)this->addUser->GetNode(-1);
        node = (UserType*)node->GetNext();
        while (node != NULL)
        {
            UserType* node2 = new UserType();
            node2->SetId(node->GetId());
            node2->SetName(node->GetName());
            node2->SetPassword(node->GetPassword());
            this->user->AddNode(node2);

            node = (UserType*)node->GetNext();
        }
        // 把添加的用户保存到数据库中
        this->addUser->Save();

    } break;
    case QMessageBox::Cancel:
    {
        // 清空添加的用户
        this->addUser->Clear();
    } break;
    default:
        break;
    }
}

void AddUser::AddUserSlot()
{
    // 没有填写信息就退出
    // 这里只检查了是否填写了id
    if (ui->idLineEdit->text().isEmpty())
    {
        return;
    }

    UserType* node = new UserType();
    node->SetId(ui->idLineEdit->text().toInt());
    node->SetName(ui->nameLineEdit->text());
    node->SetPassword(ui->passwordLineEdit->text());

    this->addUser->AddNode(node);

    this->close();
}

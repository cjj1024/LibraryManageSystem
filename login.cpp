#include <QMEssageBox>
#include <qDebug>
#include "login.h"
#include "ui_login.h"
#include "userinterface.h"
#include "admininterface.h"

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    // 设置界面的标题
    this->setWindowTitle(QString::fromLocal8Bit("登陆"));
    ui->nameLineEdit->setText("root");
    ui->passwordLineEdit->setText("root");

    // 初始化所用用户的信息
    this->user = new User();
    this->user->Init();

    // 把确定按钮与LoginSystemSlot槽连接，
    // 用户点击确定按钮后，会执行LoginSystemSlot函数
    QObject::connect(ui->loginPushButton, SIGNAL(clicked()), this,
                     SLOT(LoginSystemSlot()));
    // 把退出按钮与close槽连接，
    // 用户点击退出按钮后，会执行close函数（close是系统提供的槽），关闭界面
    QObject::connect(ui->closePushButton, SIGNAL(clicked()), this,
                     SLOT(close()));
}

Login::~Login()
{
    delete ui;

    if (this->user != NULL)
    {
        delete this->user;
        this->user = NULL;
    }
}

void Login::LoginSystemSlot()
{
    // 获得nameLineEdit的值
    QString name = ui->nameLineEdit->text();
    // 获得passwordLineEdit的值
    QString password = ui->passwordLineEdit->text();

    // 获得链表的头节点
    UserType* node = (UserType*)this->user->GetNode(-1);
    // 获得链表的第一个节点
    node = (UserType*)node->GetNext();
    // 遍历整个链表
    while (node != NULL)
    {
        // 判断用户输入是否正确
        if (node->GetName() == name && node->GetPassword() == password)
        {
            if (name == "root")
            {
                AdminInterface* w = new AdminInterface();
                w->show();
                w->ShowAllBooks();
                w->ShowAllUsers();
            }
            else
            {
                UserInterface* w = new UserInterface(node->GetId());
                // 显示界面
                w->show();
                // 显示用户已借阅的书
                w->ShowAllUserBooks();
            }
            // 登陆成功后关闭登陆界面
            this->close();
            return;
        }

        node = (UserType*)node->GetNext();
    }

    // 如果链表中没有用户输入的用户名和密码，表示输入错误
    QMessageBox::information(this, "Error Message", "Login Error, Name Or Password Error");
}


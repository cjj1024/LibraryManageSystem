#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include "user.h"

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();

public slots:
    // loginPushButton发出clicked信号时，触发这个函数
    // 判断输入的用户名与密码是否匹配
    // 如果用户名与密码正确，打开用户界面（用户名是用户）
    // ，或管理员界面（用户名是管理员）
    // 如果用户名或密码错误，提示用户输入错误
    // 调用此函数之前要初始化user变量
    void LoginSystemSlot();

private:
    Ui::Login *ui;
    // 用来储存数据库中所有的用户信息
    // 登陆系统时，用来判断用户的输入是否正确
    User* user = NULL;
};

#endif // LOGIN_H

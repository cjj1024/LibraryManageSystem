#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);

    // 当用户按下取消按钮时，界面关闭
    QObject::connect(ui->cancelPushButton, SIGNAL(clicked(bool)),
                     this, SLOT(close()));
}

Form::~Form()
{
    delete ui;
}

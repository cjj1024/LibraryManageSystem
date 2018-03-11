#include "bookinfo.h"
#include "ui_bookinfo.h"

BookInfo::BookInfo(BookType *node, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BookInfo)
{
    ui->setupUi(this);
    this->setWindowTitle(QString::fromLocal8Bit("书籍信息"));

    if (node == NULL)
    {
        return;
    }
    // 更改Label和Text Browser的显示文字
    ui->nameLabel->setText(node->GetName());
    ui->authorLabel->setText(node->GetAuthor());
    ui->categoryLabel->setText(node->GetCategory());
    ui->introductionTextBrowser->setText(node->GetIntroduction());
}

BookInfo::~BookInfo()
{
    delete ui;
}

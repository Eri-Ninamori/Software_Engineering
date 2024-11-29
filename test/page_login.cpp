#include "page_login.h"
#include "ui_page_login.h"

page_login::page_login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::page_login)
{
    ui->setupUi(this);
}

page_login::~page_login()
{
    delete ui;
}

void page_login::on_pushButton_login_clicked()
{
    // 数据库查询用户名及密码

    // 如果成功则进入主界面
    emit sendLoginSuccess();

    // 如果失败则提示错误

}


void page_login::on_pushButton_exit_clicked()
{
    // 退出嘉宾管理系统
    exit(0);
}

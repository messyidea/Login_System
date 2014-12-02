#include "dialog.h"
#include "ui_dialog.h"
#include "student.h"
student now_student;
student change_student;
Dialog::Dialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Dialog)
{
    connect(&changepw,SIGNAL(change()),this,SLOT(changepassword()));        //关联信号和对应的槽函数
    ui->setupUi(this);
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(closeit()));

}

Dialog::~Dialog()       //析构
{
    delete ui;
}
void Dialog::closeit()      //关闭界面，同时并发送信息显示登陆界面
{

    emit t();
    //this->hide();
    this->close();
}

void Dialog::on_duser_clicked()         //删除用户，发送信号并关闭
{
    emit s();
    closeit();
}

void Dialog::on_pushButton_2_clicked()      //显示修改密码界面
{
    this->changepw.show();
}

void Dialog::changepassword()           //发送修改密码的信号
{
    emit changeit();
}

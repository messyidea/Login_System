#include "change_pw.h"
#include "ui_change_pw.h"
#include "student.h"

extern student change_student;
extern student now_student;
change_pw::change_pw(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::change_pw)
{
    ui->setupUi(this);
}

change_pw::~change_pw()
{
    delete ui;
}

void change_pw::on_confirm_clicked()        //确认按钮的监听器，查看是否是合法的密码，若合法，则修改用户密码
{
    QString password1;
    password1.append(ui->newpw->text());
    string password = password1.toStdString();
    change_student = now_student;
    change_student.userpassword = password;
    //emit r();
    if(password!="")
    {
        emit change();          //发送修改密码的信号
        ui->newpw->setText("");
        ui->tips->setText("");
        this->close();
    }
    else
    {
        ui->tips->setText("password can't be null");
    }
}

void change_pw::on_pushButton_2_clicked()       //关闭按钮监听器
{
    this->close();
}

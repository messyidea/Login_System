#include "register.h"
#include "ui_register.h"
#include "student.h"

extern student new_student;
Register::Register(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);

}

Register::~Register()
{
    delete ui;
}

void Register::on_closebutton_clicked()
{
    this->close();
}

void Register::on_registercom_clicked()         //获取新的用户的账号和密码，并注册。
{
    QString newusername1;
    newusername1.append(ui->newusername->text());
    QString newuserpassword1;
    newuserpassword1.append(ui->newuserpassword->text());
    string newusername = newusername1.toStdString();
    string newuserpassword = newuserpassword1.toStdString();
    new_student.username = newusername;
    new_student.userpassword = newuserpassword;
    //emit r();
    if(newusername!=""&&newuserpassword!="")
    {
        emit r();
        ui->newusername->setText("");
        ui->newuserpassword->setText("");
        ui->tips2->setText("");
        this->close();
    }
    else
    {
        ui->tips2->setText("username or password can't be null");
    }
}

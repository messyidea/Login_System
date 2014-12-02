#ifndef DIALOG_H
#define DIALOG_H

#include <QWidget>
#include "change_pw.h"

namespace Ui {
    class Dialog;
}

class Dialog : public QWidget           //修改密码类，继承于QWidget
{
    Q_OBJECT            //宏，加入了这个才有监听机制

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
public slots:
    void closeit();         //关闭窗口
    void changepassword();  //修改密码
signals:
    void t();               //显示主界面的饿信号
    void s();               //删除用户的信号
    void changeit();        //修改用户信息的信号
private slots:
    void on_duser_clicked();        //删除用户函数

    void on_pushButton_2_clicked();     //关闭按钮的监听器

private:
    Ui::Dialog *ui;         //成员UI
    change_pw changepw;     //成员，chenge_pw
};

#endif // DIALOG_H

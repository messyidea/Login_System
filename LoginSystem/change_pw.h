#ifndef CHANGE_PW_H
#define CHANGE_PW_H

#include <QWidget>

namespace Ui {              //namespace
class change_pw;
}

class change_pw : public QWidget        //change_pw类，修改密码，继承于QWidget
{
    Q_OBJECT
    
public:
    explicit change_pw(QWidget *parent = 0);            //显示构造函数
    ~change_pw();                   //析构

signals:
    void change();          //修改密码的信号
    
private slots:              //槽，对应于各个控件的监听器
    void on_confirm_clicked();          //按了确认按钮

    void on_pushButton_2_clicked();

private:
    Ui::change_pw *ui;              //对应的UI成员变量
};

#endif // CHANGE_PW_H

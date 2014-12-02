#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dialog.h"
#include "avltree.h"
#include "student.h"
#include "avltree.h"
#include "register.h"

//#include "fstream"

namespace Ui {
    class MainWindow;
}

extern student new_student;
extern student now_student;
extern student change_student;

class MainWindow : public QMainWindow       //主界面类
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);   //显示构造函数
    ~MainWindow();
    void init();        //初始化，从文件中读入数据，在构造时调用
    void save();        //保存数据，输出到文件，析构时调用
    //void registeruser();
    //QString sss;
public slots:
    void jump();            //跳转
    void showframe();       //显示界面（表明登录成功）
    void registeruser();    //注册用户
    void deleteuser();      //删除用户
    void changeuser();      //修改用户
private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_registerbutton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;     //界面UI
    Register registerit;    //注册界面成员
    Dialog dialog;          //登录成功信息成员
    avltree<student> studenttree;   //保存信息用户信息的avl树

};




#endif // MAINWINDOW_H

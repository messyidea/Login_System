#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fstream"
#include "sstream"
#include "avltree.h"
#include "avltree.cpp"
#include "vector"

student new_student;
extern student change_student;
ostream& operator <<(ostream& os,const student& stu)            //学生类的输出流重载
{
    os<<stu.username<<":"<<stu.userpassword;
    return os;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&dialog,SIGNAL(t()),this,SLOT(showframe()));            //关联各种信号
    connect(&registerit,SIGNAL(r()),this,SLOT(registeruser()));
    connect(&dialog,SIGNAL(s()),this,SLOT(deleteuser()));
    connect(&dialog,SIGNAL(changeit()),this,SLOT(changeuser()));
    init();                         //初始化数据
    //QString s = "aaaaaaa";
    //QString ddd = QString::fromStdString(studenttree.root->data.username);
    //ui->password->setText(ddd);
    //ui->loginname->setText(sss);
}

MainWindow::~MainWindow()           //析构时保存数据
{
    save();
    delete ui;
}

void MainWindow::showframe()            //显示登录成功界面
{
    this->show();
}

void MainWindow::jump()             //跳转，跳转时并清空窗口数据
{
    dialog.show();
    this->hide();
    ui->loginname->setText("");
    ui->password->setText("");
    ui->tips1->setText("");
}

void MainWindow::on_pushButton_2_clicked()
{
    this->close();
}

void MainWindow::init()             //读取文本中的信息，建立avl树
{
    ifstream iofilereader("studentdata.data",ios::in);
    while(iofilereader.peek()!=-1){
         student userstudent;
         iofilereader>>userstudent.username>>userstudent.userpassword;
         //QString sss = QString::fromStdString(userstudent.username);
         //ui->loginname->setText(sss);
         //studenttree.insert(5);
         studenttree.insert(userstudent);
    }
    iofilereader.close();
}

void MainWindow::on_pushButton_clicked()            //获取输入的用户名和密码，并查询是否能够登录
{
    QString usernamenow1;
    usernamenow1.append(ui->loginname->text());
    QString userpasswordnow1;
    userpasswordnow1.append(ui->password->text());
    string usernamenow = usernamenow1.toStdString();
    string userpasswordnow = userpasswordnow1.toStdString();
    student studentnow;
    studentnow.username = usernamenow;
    studentnow.userpassword = userpasswordnow;
    if(studenttree.search(studentnow))
    {
        now_student.username = usernamenow;
        now_student.userpassword = userpasswordnow;
        jump();
    }
    else
    {
        ui->tips1->setText("worong password!");
    }
}

void MainWindow::on_registerbutton_clicked()
{
    registerit.show();
}

void MainWindow::registeruser()             //注册用户
{
   studenttree.insert(new_student);
    //QString ddd = QString::fromStdString(new_student.username);
    //ui->password->setText(ddd);
    //QString aaa = "adc";
    //ui->loginname->setText(aaa);
}

void MainWindow::save()             //保存数据
{
    vector<student> allstudent = studenttree.inorder2();
    ofstream iofilestudent("studentdata.data",ios::out);
    for(int i=0;i<allstudent.size();++i)
    {
        iofilestudent<<" "<<allstudent[i].username<<" "<<allstudent[i].userpassword;
    }
    iofilestudent.close();
}

void MainWindow::deleteuser()           //删除用户
{
    studenttree.deletenode(now_student);
}

void MainWindow::on_pushButton_3_clicked()          //把当前的树输出到外部文件
{
    studenttree.showinout();
}

void MainWindow::changeuser()               //修改用户
{
    studenttree.deletenode(now_student);
    studenttree.insert(change_student);
    now_student = change_student;
}

#ifndef STUDENT_H
#define STUDENT_H
#include "string"
#include "fstream"
#include "sstream"
using namespace std;
struct student              //学生类（亦是用户类）
{
public:
    student();
    string username;        //用户名
    string userpassword;    //用户密码
    bool operator<(const student b)         //重载小于符号
    {
        return username < b.username;
    }

    bool operator>(const student b)         //重载大于符号
    {
        return username > b.username;
    }
    bool operator==(const student b)        //重载等于符号
    {
        if(username == b.username && userpassword == b.userpassword) return true;
        else return false;
    }

    friend ostream& operator <<(ostream& os,const student& stu);        //友元函数，重载输出流
};




#endif // STUDENT_H

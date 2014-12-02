#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;               //主界面的类
    w.show();
    
    return a.exec();            //程序进入消息循环
}

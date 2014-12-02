#ifndef REGISTER_H
#define REGISTER_H

#include <QWidget>

namespace Ui {
    class Register;
}

class Register : public QWidget         //注册界面类
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = 0);
    ~Register();
signals:
    void r();               //注册的信号
private slots:
    void on_closebutton_clicked();

    void on_registercom_clicked();

private:
    Ui::Register *ui;
};
#endif // REGISTER_H

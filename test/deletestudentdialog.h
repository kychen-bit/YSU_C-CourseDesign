#ifndef DELETESTUDENTDIALOG_H
#define DELETESTUDENTDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include "studentmanager.h"

class DeleteStudentDialog : public QDialog {
    //Q_OBJECT 宏的使用使得该类能够利用 Qt 的信号与槽机制来处理用户输入，并且可以方便地与其他 Qt 对象进行交互。
    //此外，由于 DeleteStudentDialog 继承自 QDialog，而 QDialog 又继承自 QWidget 和 QObject，
    //因此 DeleteStudentDialog 类也间接地继承了这些基类的所有功能和特性。
    Q_OBJECT

public:
    DeleteStudentDialog(StudentManager *manager, QWidget *parent = nullptr);

//private slots 是一个类私有槽函数
private slots:
    void deleteStudent();

private:
    StudentManager *manager;
    QLineEdit *inputStudentId;
    QPushButton *submitButton;
};

#endif // DELETESTUDENTDIALOG_H

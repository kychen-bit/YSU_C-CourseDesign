#include "deletestudentdialog.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QMessageBox>
//继承QDialog，这意味着它是一个对话框窗口，通常用于短期任务和与用户的简短通信
DeleteStudentDialog::DeleteStudentDialog(StudentManager *manager, QWidget *parent)
    : QDialog(parent), manager(manager) {
    setWindowTitle("删除学生信息");
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    inputStudentId = new QLineEdit(this);
    inputStudentId->setPlaceholderText("输入学号 (如: 01)");
    mainLayout->addWidget(new QLabel("学号:", this));
    mainLayout->addWidget(inputStudentId);


    submitButton = new QPushButton("删除", this);
    submitButton->setStyleSheet("font-size: 14px; padding: 8px; background-color: #f44336; color: white; border-radius: 5px;");
    mainLayout->addWidget(submitButton);

    connect(submitButton, &QPushButton::clicked, this, &DeleteStudentDialog::deleteStudent);
}

void DeleteStudentDialog::deleteStudent() {
    QString studentId = inputStudentId->text();
    if (studentId.isEmpty()) {
        QMessageBox::warning(this, "错误", "请输入学号！");
        return;
    }

    manager->deleteStudent(studentId);
    QMessageBox::information(this, "成功", "学生删除成功！");
    accept();
}

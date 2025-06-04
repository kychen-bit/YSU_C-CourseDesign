#ifndef ADDCOURSEDIALOG_H
#define ADDCOURSEDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include "studentmanager.h"

class AddCourseDialog : public QDialog {
    Q_OBJECT

public:
    AddCourseDialog(StudentManager *manager, QWidget *parent = nullptr);

private slots:
    void addCourse();

private:
    StudentManager *manager;
    //输入对话框组件
    QLineEdit *inputStudentId;
    QLineEdit *inputCourseId;
    QLineEdit *inputCourseName;
    QLineEdit *inputCredit;
    QLineEdit *inputRegularScore;
    QLineEdit *inputLabScore;
    QLineEdit *inputExamScore;
    //提交按钮设置
    QPushButton *submitButton;
};

#endif // ADDCOURSEDIALOG_H

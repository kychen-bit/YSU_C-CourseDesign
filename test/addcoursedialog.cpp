#include "addcoursedialog.h"
#include <QVBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QMessageBox>

AddCourseDialog::AddCourseDialog(StudentManager *manager, QWidget *parent)
    : QDialog(parent), manager(manager) {
    setWindowTitle("录入课程信息");
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    QGridLayout *inputLayout = new QGridLayout();

    inputStudentId = new QLineEdit(this);
    inputStudentId->setPlaceholderText("学号 (如: 01)");
    inputCourseId = new QLineEdit(this);
    inputCourseId->setPlaceholderText("课程编号 (如: A01)");
    inputCourseName = new QLineEdit(this);
    inputCourseName->setPlaceholderText("课程名称 (如: 大学物理)");
    inputCredit = new QLineEdit(this);
    inputCredit->setPlaceholderText("学分 (如: 3)");
    inputRegularScore = new QLineEdit(this);
    inputRegularScore->setPlaceholderText("平时成绩 (如: 66)");
    inputLabScore = new QLineEdit(this);
    inputLabScore->setPlaceholderText("实验成绩 (如: 78, -1表示无实验)");
    inputExamScore = new QLineEdit(this);
    inputExamScore->setPlaceholderText("卷面成绩 (如: 82)");

    inputLayout->addWidget(new QLabel("学号:"), 0, 0);
    inputLayout->addWidget(inputStudentId, 0, 1);
    inputLayout->addWidget(new QLabel("课程编号:"), 1, 0);
    inputLayout->addWidget(inputCourseId, 1, 1);
    inputLayout->addWidget(new QLabel("课程名称:"), 2, 0);
    inputLayout->addWidget(inputCourseName, 2, 1);
    inputLayout->addWidget(new QLabel("学分:"), 3, 0);
    inputLayout->addWidget(inputCredit, 3, 1);
    inputLayout->addWidget(new QLabel("平时成绩:"), 4, 0);
    inputLayout->addWidget(inputRegularScore, 4, 1);
    inputLayout->addWidget(new QLabel("实验成绩:"), 5, 0);
    inputLayout->addWidget(inputLabScore, 5, 1);
    inputLayout->addWidget(new QLabel("卷面成绩:"), 6, 0);
    inputLayout->addWidget(inputExamScore, 6, 1);

    submitButton = new QPushButton("提交", this);
    submitButton->setStyleSheet("font-size: 14px; padding: 8px; background-color: #4CAF50; color: white; border-radius: 5px;");
    inputLayout->addWidget(submitButton, 7, 0, 1, 2);

    mainLayout->addLayout(inputLayout);
    //连接到addcourse槽函数
    connect(submitButton, &QPushButton::clicked, this, &AddCourseDialog::addCourse);
}

void AddCourseDialog::addCourse() {
    if (inputStudentId->text().isEmpty() || inputCourseId->text().isEmpty() ||
        inputCourseName->text().isEmpty() || inputCredit->text().isEmpty() ||
        inputRegularScore->text().isEmpty() || inputLabScore->text().isEmpty() ||
        inputExamScore->text().isEmpty()) {
        QMessageBox::warning(this, "错误", "请填写所有课程信息！");
        return;
    }

    bool ok;
    double credit = inputCredit->text().toDouble(&ok);
    //错误情况的提示
    if (!ok || credit <= 0) {
        QMessageBox::warning(this, "错误", "学分必须为正数！");
        return;
    }

    double regularScore = inputRegularScore->text().toDouble(&ok);
    if (!ok || regularScore < 0 || regularScore > 100) {
        QMessageBox::warning(this, "错误", "平时成绩必须在0-100之间！");
        return;
    }

    double labScore = inputLabScore->text().toDouble(&ok);
    if (!ok || (labScore != -1 && (labScore < 0 || labScore > 100))) {
        QMessageBox::warning(this, "错误", "实验成绩必须为-1或0-100之间！");
        return;
    }

    double examScore = inputExamScore->text().toDouble(&ok);
    if (!ok || examScore < 0 || examScore > 100) {
        QMessageBox::warning(this, "错误", "卷面成绩必须在0-100之间！");
        return;
    }

    Course course(inputStudentId->text(), inputCourseId->text(), inputCourseName->text(),
                  credit, regularScore, labScore, examScore);
    manager->addCourse(course);
    QMessageBox::information(this, "成功", "课程添加成功！");
    accept();
}

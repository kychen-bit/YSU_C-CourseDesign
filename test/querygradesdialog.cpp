#include "querygradesdialog.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QMessageBox>

QueryGradesDialog::QueryGradesDialog(StudentManager *manager, QWidget *parent)
    : QDialog(parent), manager(manager) {
    setWindowTitle("查询学生成绩");
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    inputStudentId = new QLineEdit(this);
    inputStudentId->setPlaceholderText("输入学号 (如: 01)");
    mainLayout->addWidget(new QLabel("学号:", this));
    mainLayout->addWidget(inputStudentId);

    submitButton = new QPushButton("查询", this);
    submitButton->setStyleSheet("font-size: 14px; padding: 8px; background-color: #4CAF50; color: white; border-radius: 5px;");
    mainLayout->addWidget(submitButton);

    output = new QTextEdit(this);
    output->setReadOnly(true);
    output->setStyleSheet("font-size: 14px;");
    mainLayout->addWidget(new QLabel("查询结果:", this));
    mainLayout->addWidget(output);

    connect(submitButton, &QPushButton::clicked, this, &QueryGradesDialog::queryGrades);
}

void QueryGradesDialog::queryGrades() {
    QString studentId = inputStudentId->text();
    if (studentId.isEmpty()) {
        QMessageBox::warning(this, "错误", "请输入学号！");
        return;
    }

    QList<Course> courses = manager->findCoursesByStudentId(studentId);
    QString result;
    double totalCredit = 0;
    int courseCount = courses.size();
    for (const Course& course : courses) {
        result += QString("课程编号: %1 课程名称: %2 综合成绩: %3 实得学分: %4\n")
                      .arg(course.courseId, course.courseName)
                      .arg(course.finalScore, 0, 'f', 2)
                      .arg(course.actualCredit, 0, 'f', 2);
        totalCredit += course.actualCredit;
    }
    result += QString("共修: %1 科，实得总学分为: %2\n").arg(courseCount).arg(totalCredit, 0, 'f', 2);
    output->setText(result.isEmpty() ? "未找到成绩！" : result);
}

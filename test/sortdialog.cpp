#include "sortdialog.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>

SortDialog::SortDialog(StudentManager *manager, QWidget *parent)
    : QDialog(parent), manager(manager) {
    setWindowTitle("排序成绩");
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    finalScoreAscButton = new QPushButton("综合成绩升序", this);
    finalScoreDescButton = new QPushButton("综合成绩降序", this);
    actualCreditAscButton = new QPushButton("实得学分升序", this);
    actualCreditDescButton = new QPushButton("实得学分降序", this);

    QString buttonStyle = "font-size: 14px; padding: 8px; background-color: #4CAF50; color: white; border-radius: 5px;";
    finalScoreAscButton->setStyleSheet(buttonStyle);
    finalScoreDescButton->setStyleSheet(buttonStyle);
    actualCreditAscButton->setStyleSheet(buttonStyle);
    actualCreditDescButton->setStyleSheet(buttonStyle);

    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(finalScoreAscButton);
    buttonLayout->addWidget(finalScoreDescButton);
    buttonLayout->addWidget(actualCreditAscButton);
    buttonLayout->addWidget(actualCreditDescButton);
    mainLayout->addLayout(buttonLayout);

    output = new QTextEdit(this);
    output->setReadOnly(true);
    output->setStyleSheet("font-size: 14px;");
    mainLayout->addWidget(new QLabel("排序结果:", this));
    mainLayout->addWidget(output);

    connect(finalScoreAscButton, &QPushButton::clicked, this, &SortDialog::sortByFinalScoreAsc);
    connect(finalScoreDescButton, &QPushButton::clicked, this, &SortDialog::sortByFinalScoreDesc);
    connect(actualCreditAscButton, &QPushButton::clicked, this, &SortDialog::sortByActualCreditAsc);
    connect(actualCreditDescButton, &QPushButton::clicked, this, &SortDialog::sortByActualCreditDesc);
}

void SortDialog::sortByFinalScoreAsc() {
    QList<Course> sortedCourses = manager->sortCoursesByFinalScore(true);
    QString result;
    for (const Course& course : sortedCourses) {
        result += QString("学号: %1 课程编号: %2 课程名称: %3 综合成绩: %4 实得学分: %5\n")
                      .arg(course.studentId, course.courseId, course.courseName)
                      .arg(course.finalScore, 0, 'f', 2)
                      .arg(course.actualCredit, 0, 'f', 2);
    }
    output->setText(result.isEmpty() ? "无成绩数据！" : result);
}

void SortDialog::sortByFinalScoreDesc() {
    QList<Course> sortedCourses = manager->sortCoursesByFinalScore(false);
    QString result;
    for (const Course& course : sortedCourses) {
        result += QString("学号: %1 课程编号: %2 课程名称: %3 综合成绩: %4 实得学分: %5\n")
                      .arg(course.studentId, course.courseId, course.courseName)
                      .arg(course.finalScore, 0, 'f', 2)
                      .arg(course.actualCredit, 0, 'f', 2);
    }
    output->setText(result.isEmpty() ? "无成绩数据！" : result);
}

void SortDialog::sortByActualCreditAsc() {
    QList<Course> sortedCourses = manager->sortCoursesByActualCredit(true);
    QString result;
    for (const Course& course : sortedCourses) {
        result += QString("学号: %1 课程编号: %2 课程名称: %3 综合成绩: %4 实得学分: %5\n")
                      .arg(course.studentId, course.courseId, course.courseName)
                      .arg(course.finalScore, 0, 'f', 2)
                      .arg(course.actualCredit, 0, 'f', 2);
    }
    output->setText(result.isEmpty() ? "无成绩数据！" : result);
}

void SortDialog::sortByActualCreditDesc() {
    QList<Course> sortedCourses = manager->sortCoursesByActualCredit(false);
    QString result;
    for (const Course& course : sortedCourses) {
        result += QString("学号: %1 课程编号: %2 课程名称: %3 综合成绩: %4 实得学分: %5\n")
                      .arg(course.studentId, course.courseId, course.courseName)
                      .arg(course.finalScore, 0, 'f', 2)
                      .arg(course.actualCredit, 0, 'f', 2);
    }
    output->setText(result.isEmpty() ? "无成绩数据！" : result);
}

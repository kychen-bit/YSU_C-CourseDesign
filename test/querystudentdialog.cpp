#include "querystudentdialog.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QMessageBox>

QueryStudentDialog::QueryStudentDialog(StudentManager *manager, QWidget *parent)
    : QDialog(parent), manager(manager) {
    setWindowTitle("查询学生信息");
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    inputQuery = new QLineEdit(this);
    inputQuery->setPlaceholderText("输入学号或姓名 (如: 01 或 张成成)");
    mainLayout->addWidget(new QLabel("学号/姓名:", this) );
    mainLayout->addWidget(inputQuery);

    submitButton = new QPushButton("查询", this);
    submitButton->setStyleSheet("font-size: 14px; padding: 8px; background-color: #4CAF50; color: white; border-radius: 5px;");
    mainLayout->addWidget(submitButton);

    output = new QTextEdit(this);
    output->setReadOnly(true);
    output->setStyleSheet("font-size: 14px;");
    mainLayout->addWidget(new QLabel("查询结果:", this));
    mainLayout->addWidget(output);

    connect(submitButton, &QPushButton::clicked, this, &QueryStudentDialog::queryStudent);
}

void QueryStudentDialog::queryStudent() {
    QString keyword = inputQuery->text();
    if (keyword.isEmpty()) {
        QMessageBox::warning(this, "错误", "请输入学号或姓名！");
        return;
    }

    QList<Student> students = manager->findStudentsByIdOrName(keyword);
    QString result;
    for (const Student& student : students) {
        result += QString("学号: %1 姓名: %2 性别: %3 宿舍: %4 电话: %5\n")
                      .arg(student.id, student.name, student.gender, student.dorm, student.phone);
    }
    output->setText(result.isEmpty() ? "未找到学生！" : result);
}

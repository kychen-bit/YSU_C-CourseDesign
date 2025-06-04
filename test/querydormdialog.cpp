#include "querydormdialog.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QMessageBox>

QueryDormDialog::QueryDormDialog(StudentManager *manager, QWidget *parent)
    : QDialog(parent), manager(manager) {
    setWindowTitle("查询宿舍学生");
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    inputDorm = new QLineEdit(this);
    inputDorm->setPlaceholderText("输入宿舍号码 (如: 501)");
    mainLayout->addWidget(new QLabel("宿舍号码:", this));
    mainLayout->addWidget(inputDorm);

    submitButton = new QPushButton("查询", this);
    submitButton->setStyleSheet("font-size: 14px; padding: 8px; background-color: #4CAF50; color: white; border-radius: 5px;");
    mainLayout->addWidget(submitButton);

    output = new QTextEdit(this);
    output->setReadOnly(true);
    output->setStyleSheet("font-size: 14px;");
    mainLayout->addWidget(new QLabel("查询结果:", this));
    mainLayout->addWidget(output);

    connect(submitButton, &QPushButton::clicked, this, &QueryDormDialog::queryDorm);
}

void QueryDormDialog::queryDorm() {
    QString dorm = inputDorm->text();
    if (dorm.isEmpty()) {
        QMessageBox::warning(this, "错误", "请输入宿舍号码！");
        return;
    }

    QList<Student> students = manager->findStudentsByDorm(dorm);
    QString result;
    for (const Student& student : students) {
        result += QString("学号: %1 姓名: %2 性别: %3 宿舍: %4 电话: %5\n")
                      .arg(student.id, student.name, student.gender, student.dorm, student.phone);
    }
    output->setText(result.isEmpty() ? "未找到宿舍学生！" : result);
}

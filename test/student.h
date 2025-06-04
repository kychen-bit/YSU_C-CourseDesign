#ifndef STUDENT_H
#define STUDENT_H

#include <QString>

class Student {
public:
    QString id;        // 学号
    QString name;      // 姓名
    QString gender;    // 性别
    QString dorm;      // 宿舍号码
    QString phone;     // 电话号码

    Student() {}
    Student(const QString& id, const QString& name, const QString& gender,
            const QString& dorm, const QString& phone)
        : id(id), name(name), gender(gender), dorm(dorm), phone(phone) {}
};

#endif // STUDENT_H

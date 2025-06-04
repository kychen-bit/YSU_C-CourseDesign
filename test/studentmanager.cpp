#include "studentmanager.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <algorithm>

StudentManager::StudentManager() {}

void StudentManager::loadStudents(const QString& filename) {
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "无法打开学生文件:" << filename;
        return;
    }

    QTextStream in(&file);
    students.clear();
    //使用正则表达式分割每行内容，确保至少有5个部分
    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        if (line.isEmpty()) continue;
        // \s表示空白字符，+表示多个，(QRegularExpression("\\s+")表示匹配一个或多个空白字符
        QStringList parts = line.split(QRegularExpression("\\s+"));
        if (parts.size() >= 5) {
            Student student(parts[0], parts[1], parts[2], parts[3], parts[4]);
            students.append(student);
        }
    }
    file.close();
}

void StudentManager::loadCourses(const QString& filename) {
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "无法打开成绩文件:" << filename;
        return;
    }

    QTextStream in(&file);
    courses.clear();
    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        if (line.isEmpty()) continue;
        QStringList parts = line.split(QRegularExpression("\\s+"));
        if (parts.size() >= 7) {
            Course course(parts[0], parts[1], parts[2], parts[3].toDouble(),
                          parts[4].toDouble(), parts[5].toDouble(), parts[6].toDouble());
            courses.append(course);
        }
    }
    file.close();
}

void StudentManager::saveCourses(const QString& filename) {
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "无法保存成绩文件:" << filename;
        return;
    }

    QTextStream out(&file);
    for (const Course& course : courses) {
        out << course.studentId << " " << course.courseId << " " << course.courseName << " "
            << course.credit << " " << course.regularScore << " " << course.labScore << " "
            << course.examScore << " " << course.finalScore << " " << course.actualCredit << "\n";
    }
    file.close();
}

void StudentManager::addCourse(const Course& course) {
    courses.append(course);
    saveCourses("B.txt");
}

//通过lambda表达式来判断id是否相等
void StudentManager::deleteStudent(const QString& studentId) {
    // 删除学生信息
    // 操作的是student容器
    students.erase(std::remove_if(students.begin(), students.end(),
                                  [&studentId](const Student& s) { return s.id == studentId; }), students.end());

    // 删除相关成绩
    // 操作的是course容器
    courses.erase(std::remove_if(courses.begin(), courses.end(),[&studentId](const Course& c)
                                 { return c.studentId == studentId; }), courses.end());
    saveCourses("B.txt");
}

QList<Student> StudentManager::findStudentsByIdOrName(const QString& keyword) {
    QList<Student> result;
    //Based-for循环：常用于遍历容器中的元素，没有显式的索引，更加高效
    //遍历容器找到匹配的所有值，存储在Student容器中
    for (const Student& student : students) {
        if (student.id == keyword || student.name == keyword) {
            result.append(student);
        }
    }
    return result;
}

QList<Student> StudentManager::findStudentsByDorm(const QString& dorm) {
    QList<Student> result;
    for (const Student& student : students) {
        if (student.dorm == dorm) {
            result.append(student);
        }
    }
    return result;
}

QList<Course> StudentManager::findCoursesByStudentId(const QString& studentId) {
    QList<Course> result;
    for (const Course& course : courses) {
        if (course.studentId == studentId) {
            result.append(course);
        }
    }
    return result;
}

//bool类型的ascending变量用于决定排序是升序还是降序
//用自带的sort函数遍历学生和课程容器来进行排序
//通过lambda表达式定义排序的比较逻辑
QList<Course> StudentManager::sortCoursesByFinalScore(bool ascending) {
    QList<Course> sortedCourses = courses;
    std::sort(sortedCourses.begin(), sortedCourses.end(),
              [ascending](const Course& a, const Course& b) {
                  return ascending ? a.finalScore < b.finalScore : a.finalScore > b.finalScore;//ascending为true则1否则为2
              });
    return sortedCourses;
}

QList<Course> StudentManager::sortCoursesByActualCredit(bool ascending) {
    QList<Course> sortedCourses = courses;
    std::sort(sortedCourses.begin(), sortedCourses.end(),
              [ascending](const Course& a, const Course& b) {
                  return ascending ? a.actualCredit < b.actualCredit : a.actualCredit > b.actualCredit;
              });
    return sortedCourses;
}

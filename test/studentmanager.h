#ifndef STUDENTMANAGER_H
#define STUDENTMANAGER_H

#include <QList>
#include <QString>
#include "student.h"
#include "course.h"
#include <QRegularExpression>
class StudentManager {
public:
    StudentManager();
    void loadStudents(const QString& filename);
    void loadCourses(const QString& filename);
    void saveCourses(const QString& filename);
    void addCourse(const Course& course);
    void deleteStudent(const QString& studentId);
    QList<Student> findStudentsByIdOrName(const QString& keyword);
    QList<Student> findStudentsByDorm(const QString& dorm);
    QList<Course> findCoursesByStudentId(const QString& studentId);
    QList<Course> sortCoursesByFinalScore(bool ascending);
    QList<Course> sortCoursesByActualCredit(bool ascending);

private:
    QList<Student> students;
    QList<Course> courses;
};

#endif // STUDENTMANAGER_H

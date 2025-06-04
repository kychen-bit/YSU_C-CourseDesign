#ifndef COURSE_H
#define COURSE_H

#include <QString>

class Course {
public:
    QString studentId;  // 学号
    QString courseId;  // 课程编号
    QString courseName;// 课程名称
    double credit;     // 学分
    double regularScore; // 平时成绩
    double labScore;   // 实验成绩
    double examScore;  // 卷面成绩
    double finalScore; // 综合成绩
    double actualCredit; // 实得学分

    Course() : regularScore(0), labScore(-1), examScore(0), finalScore(0), actualCredit(0) {}
    Course(const QString& studentId, const QString& courseId, const QString& courseName,
           double credit, double regularScore, double labScore, double examScore)
        : studentId(studentId), courseId(courseId), courseName(courseName),
        credit(credit), regularScore(regularScore), labScore(labScore),
        examScore(examScore) {
        calculateFinalScore();
        calculateActualCredit();
    }

    void calculateFinalScore();
    void calculateActualCredit();

private:
         // 计算综合成绩和实得学分的内部方法
};

#endif // COURSE_H

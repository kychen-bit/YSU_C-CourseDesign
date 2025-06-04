#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include "studentmanager.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private slots:
    void openAddCourseDialog();
    void openQueryStudentDialog();
    void openQueryDormDialog();
    void openQueryGradesDialog();
    void openDeleteStudentDialog();
    void openSortDialog();

private:
    StudentManager manager;
    QPushButton *addCourseButton;
    QPushButton *queryStudentButton;
    QPushButton *queryDormButton;
    QPushButton *queryGradesButton;
    QPushButton *deleteStudentButton;
    QPushButton *sortButton;

    void setupUI();
};

#endif // MAINWINDOW_H

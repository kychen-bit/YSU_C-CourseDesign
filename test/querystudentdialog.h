#ifndef QUERYSTUDENTDIALOG_H
#define QUERYSTUDENTDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include "studentmanager.h"

class QueryStudentDialog : public QDialog {
    Q_OBJECT

public:
    QueryStudentDialog(StudentManager *manager, QWidget *parent = nullptr);

private slots:
    void queryStudent();

private:
    StudentManager *manager;
    QLineEdit *inputQuery;
    QTextEdit *output;
    QPushButton *submitButton;
};

#endif // QUERYSTUDENTDIALOG_H

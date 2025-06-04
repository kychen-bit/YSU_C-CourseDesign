#ifndef QUERYGRADESDIALOG_H
#define QUERYGRADESDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include "studentmanager.h"

class QueryGradesDialog : public QDialog {
    Q_OBJECT

public:
    QueryGradesDialog(StudentManager *manager, QWidget *parent = nullptr);

private slots:
    void queryGrades();

private:
    StudentManager *manager;
    QLineEdit *inputStudentId;
    QTextEdit *output;
    QPushButton *submitButton;
};

#endif // QUERYGRADESDIALOG_H

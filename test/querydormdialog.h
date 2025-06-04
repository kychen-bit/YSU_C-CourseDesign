#ifndef QUERYDORMDIALOG_H
#define QUERYDORMDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include "studentmanager.h"

class QueryDormDialog : public QDialog {
    Q_OBJECT

public:
    QueryDormDialog(StudentManager *manager, QWidget *parent = nullptr);

private slots:
    void queryDorm();

private:
    StudentManager *manager;
    QLineEdit *inputDorm;
    QTextEdit *output;
    QPushButton *submitButton;
};

#endif // QUERYDORMDIALOG_H

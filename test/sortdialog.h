#ifndef SORTDIALOG_H
#define SORTDIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QTextEdit>
#include "studentmanager.h"

class SortDialog : public QDialog {
    Q_OBJECT

public:
    SortDialog(StudentManager *manager, QWidget *parent = nullptr);

private slots:
    void sortByFinalScoreAsc();
    void sortByFinalScoreDesc();
    void sortByActualCreditAsc();
    void sortByActualCreditDesc();

private:
    StudentManager *manager;
    QTextEdit *output;
    QPushButton *finalScoreAscButton;
    QPushButton *finalScoreDescButton;
    QPushButton *actualCreditAscButton;
    QPushButton *actualCreditDescButton;
};

#endif // SORTDIALOG_H

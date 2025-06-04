#include "mainwindow.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QPalette>
#include <QPixmap>
#include "addcoursedialog.h"
#include "querystudentdialog.h"
#include "querydormdialog.h"
#include "querygradesdialog.h"
#include "deletestudentdialog.h"
#include "sortdialog.h"

//主窗口初始化
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    manager.loadStudents("A.txt");
    manager.loadCourses("B.txt");
    setupUI();
    setWindowTitle("学生管理系统");
    resize(600, 400);
}

//用户界面设置
void MainWindow::setupUI() {
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    // 设置背景图片
    QPalette palette;
    QPixmap background("bkImage.jpg"); // 图片路径，在debug文件目录下
    if (!background.isNull()) {
        palette.setBrush(QPalette::Window, background.scaled(size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
        centralWidget->setPalette(palette);
        centralWidget->setAutoFillBackground(true);
    } else {
        centralWidget->setStyleSheet("background-color: #f0f0f0;");
    }
    //QVBoxLayout（布局管理器）用于管理主窗口界面的对齐方式和间距
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);
    mainLayout->setAlignment(Qt::AlignCenter);//按钮居中对齐
    mainLayout->setSpacing(20);//按钮间距为20

    // 主界面标题的对齐方和间距
    QLabel *titleLabel = new QLabel("学生管理系统", this);
    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setStyleSheet("font-size: 24px; font-weight: bold; color: #333; background-color: rgba(240, 240, 240, 0.8); padding: 10px;");
    mainLayout->addWidget(titleLabel);

    // 功能按钮
    addCourseButton = new QPushButton("录入课程信息", this);
    queryStudentButton = new QPushButton("查询学生信息", this);
    queryDormButton = new QPushButton("查询宿舍学生", this);
    queryGradesButton = new QPushButton("查询学生成绩", this);
    deleteStudentButton = new QPushButton("删除学生信息", this);
    sortButton = new QPushButton("排序成绩信息", this);

    // 按钮样式
    QString buttonStyle = "QPushButton { font-size: 16px; padding: 10px; background-color: #1011A1; color: white; border-radius: 5px; }"
                          "QPushButton:hover { background-color: #45a049; }";
    addCourseButton->setStyleSheet(buttonStyle);
    queryStudentButton->setStyleSheet(buttonStyle);
    queryDormButton->setStyleSheet(buttonStyle);
    queryGradesButton->setStyleSheet(buttonStyle);
    deleteStudentButton->setStyleSheet(buttonStyle);
    sortButton->setStyleSheet(buttonStyle);

    mainLayout->addWidget(addCourseButton);
    mainLayout->addWidget(queryStudentButton);
    mainLayout->addWidget(queryDormButton);
    mainLayout->addWidget(queryGradesButton);
    mainLayout->addWidget(deleteStudentButton);
    mainLayout->addWidget(sortButton);
    mainLayout->addStretch();

    // 连接信号和槽
    //利用Qt中的信号与槽机制（实现组件间的通信）
    //Q_Object::connect(const QObject *sender, const char *signal, const QObject *receiver, const char *method, Qt::ConnectionType type = Qt::AutoConnection);
    //slot：接收信号后需要调用的函数
    connect(addCourseButton, &QPushButton::clicked, this, &MainWindow::openAddCourseDialog);
    connect(queryStudentButton, &QPushButton::clicked, this, &MainWindow::openQueryStudentDialog);
    connect(queryDormButton, &QPushButton::clicked, this, &MainWindow::openQueryDormDialog);
    connect(queryGradesButton, &QPushButton::clicked, this, &MainWindow::openQueryGradesDialog);
    connect(deleteStudentButton, &QPushButton::clicked, this, &MainWindow::openDeleteStudentDialog);
    connect(sortButton, &QPushButton::clicked, this, &MainWindow::openSortDialog);
}

void MainWindow::openAddCourseDialog() {
    AddCourseDialog dialog(&manager, this);
    dialog.exec();
}

void MainWindow::openQueryStudentDialog() {
    QueryStudentDialog dialog(&manager, this);
    dialog.exec();
}

void MainWindow::openQueryDormDialog() {
    QueryDormDialog dialog(&manager, this);
    dialog.exec();
}

void MainWindow::openQueryGradesDialog() {
    QueryGradesDialog dialog(&manager, this);
    dialog.exec();
}

void MainWindow::openDeleteStudentDialog() {
    DeleteStudentDialog dialog(&manager, this);
    dialog.exec();
}

void MainWindow::openSortDialog() {
    SortDialog dialog(&manager, this);
    dialog.exec();
}

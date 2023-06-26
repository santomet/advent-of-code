#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    // ERROR connect - TODO
    // connect(ui->textEdit, &QPushButton::clicked,
            // this, &MainWindow::on_pushButton_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}


int MainWindow::on_pushButton_clicked()
{
    QString searchString = ui->lineEdit->text();
    int actionNumber = searchString.toInt();

    return actionNumber;
}


void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{

}


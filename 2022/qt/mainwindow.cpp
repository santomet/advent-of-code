#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <iostream>
#include <QString>
#include <string>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    // ERROR connect - TODO
    // connect(ui->textEdit, &QPushButton::clicked,
            // this, &MainWindow::on_pushButton_clicked);

    ui->comboBox->addItems({"1", "2", "3"});
    gb.setLayout(ui->radioButtonLayout);

    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::execute);
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::execute()
{
    QString input = ui->lineEdit->text();
    int i = ui->comboBox->currentIndex();
    int part = ui->radioButtonp1->isChecked() ? 1 : 2;
    ui->textEdit->setText("aaa");
}


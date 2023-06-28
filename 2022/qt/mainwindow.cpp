#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "aoc2022.h"

#include <iostream>
#include <QString>
#include <string>
#include <QTextStream>
#include <format>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    ui->comboBox->addItems({"1", "2", "3"});
    // gb.setLayout(ui->radioButtonLayout);

    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::execute);

    // aocSwitch(i);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// void MainWindow::aocSwitch(int choice) {

    // // AoC2022 AoC;
    // // QTextStream qout(stdout);
// }


// Part 1 and 2 could be used for inner and outer testing (array and file)

void MainWindow::execute()
{
    AoC2022 AoC;
    // QString input = ui->lineEdit->text();
    // int i = ui->comboBox->currentIndex();
    // int part = ui->radioButtonp1->isChecked() ? 1 : 2;
    // ui->textEdit->setText("aaa");

    int choice = ui->comboBox->currentIndex() + 1;

    switch (choice) {
    case 1:
        ui->textEdit->setText(QString("The result is %1 \n").arg(AoC.day_01()));
        break;
    case 2:
        ui->textEdit->setText("No result yet");
        break;
    case 3:
        ui->textEdit->setText("No result yet");
        break;
    default:
        break;
    }
}


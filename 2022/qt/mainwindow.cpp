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


    ui->comboBox->addItems({"1", "2", "3", "4"});
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


void MainWindow::execute()
{
    AoC2022 AoC;
    // QString input = ui->lineEdit->text();
    // int i = ui->comboBox->currentIndex();
    // ui->textEdit->setText("aaa");

    QString output_text = "The result is %1 \n";
    int choice = ui->comboBox->currentIndex() + 1;
    int part = ui->radioButtonp1->isChecked() ? 1 : 2;

    switch (choice) {
    case 1:
        output_text = part == 1 ? output_text.arg(AoC.day_01_1()) : output_text.arg(AoC.day_01_2());
        ui->textEdit->setText(output_text);

        break;
    case 2:
        output_text = part == 1 ? output_text.arg(AoC.day_02_1()) : output_text.arg(AoC.day_02_2());
        ui->textEdit->setText(output_text);
        break;
    case 3:
        output_text = part == 1 ? output_text.arg(AoC.day_03_1()) : output_text.arg(AoC.day_03_2());
        ui->textEdit->setText(output_text);
        break;
    case 4:
        output_text = part == 1 ? output_text.arg(AoC.day_04_1()) : output_text.arg(AoC.day_04_2());
        ui->textEdit->setText(output_text);
        break;
    default:
        break;
    }
}














#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGroupBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    // void aocSwitch(int choice);

private slots:
    void execute();


private:
    Ui::MainWindow *ui;
    QGroupBox gb;
};
#endif // MAINWINDOW_H

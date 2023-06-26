#include "mainwindow.h"
#include "mainwindow.cpp"

#include <QApplication>
#include <QLineEdit>
#include <QPushButton>
#include <QTextStream>


#include <string>
#include <iostream>

using namespace std;

void days()
{
    MainWindow window;
    QTextStream qout(stdout);
    // int dayNumber = window;

}

// void hello_world_qt() {
    // QTextStream qin(stdin);
    // QTextStream qout(stdout);

    // qout << "HELLOOOOOO gimme your name: ";
    // qout.flush();
    // QString name = qin.readLine();
    // qout << "HELLO" << name;
    // qout.flush();
// }

// void nevim() {
    // // QPushButton *button = new QPushButton("&Download", this);
// }

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow window;





    window.show();
    return app.exec();
}

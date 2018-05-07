/**
  * @file main.cpp
  * @author Jan Koci (xkocij01), Petr Zubalik (xzubal04)
  * @date May 2018
  * @brief  Main file of the project
  *
  */

#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setGeometry(100, 100, 1200, 650);
    w.show();

    return a.exec();
}

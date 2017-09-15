#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "scripter.h"

#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow();
private slots:
    void scriptRun();
    void about();
private:
    void createActions();
    Scripter scripter;
};
#endif

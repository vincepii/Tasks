#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QWidget>
#include "ui_MainWindow.h"

#include "TaskCollection.h"
#include "TaskService.h"

class MainWindow : public QWidget
{
    core::TaskCollection taskCollection_;
    Q_OBJECT

public:
    MainWindow(core::TaskService *taskService, QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindowClass ui;
};

#endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QWidget>
#include "ui_MainWindow.h"

#include "TaskCollection.h"
#include "TaskService.h"

class MainWindow : public QWidget
{
    /** Task collection core object */
    core::TaskCollection taskCollection_;

    Q_OBJECT

public:

    /**
     * Constructor.
     * @param taskService Task service implementation
     * @param parent Qt parent
     */
    MainWindow(core::TaskService *taskService, QWidget *parent = 0);

    /**
     * Destructor
     */
    ~MainWindow();

public slots:

    /**
     * Slot to TaskWidget synchTaskSignal
     */
    void synchTaskSlot(std::string id);

    /**
     * Slot to TaskWidget deleteTaskSignal
     */
    void deleteTaskSlot(std::string id);

private:
    Ui::MainWindowClass ui;
};

#endif // MAINWINDOW_H

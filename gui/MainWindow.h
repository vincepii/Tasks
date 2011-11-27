#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QWidget>
#include "ui_MainWindow.h"

#include "TaskCollection.h"
#include "TaskService.h"
#include "TaskWidget.h"

class MainWindow : public QWidget
{
    /** Task collection core object */
    core::TaskCollection taskCollection_;

    /** Mutex to regulate taskCollection_ access during network operations */
    pthread_mutex_t synchMutex_;

    Q_OBJECT

public:

    /**
     * Data structure to pass parameters to synch thread
     */
    struct ThreadParameters {
        MainWindow *classReference;
        TaskWidget *callerTask;
        std::string id;
    };

public:

    /**
     * Constructor.
     * @param taskService Task service implementation
     * @param parent Qt parent
     */
    MainWindow(core::TaskService *taskService, QWidget *parent = 0);

    /**
     * TaskCollection getter
     * @return TaskCollection
     */
    core::TaskCollection &getTaskCollection();

    /**
     * Method to acquire the mutex on task collection
     */
    void lockTaskCollection();

    /**
     * Method to release the mutex on task collection
     */
    void unlockTaskCollection();

    /**
     * Destructor
     */
    ~MainWindow();

public slots:

    /**
     * Slot to TaskWidget synchTaskSignal
     */
    void synchTaskSlot(std::string &id);

    /**
     * Slot to TaskWidget deleteTaskSignal
     */
    void deleteTaskSlot(std::string &id);

private:
    Ui::MainWindowClass ui;
};

#endif // MAINWINDOW_H

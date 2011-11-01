#include "MainWindow.h"

#include <map>
#include <QLineEdit>
#include "Task.h"
#include "TaskWidget.h"

MainWindow::MainWindow(core::TaskService *taskService, QWidget *parent)
: QWidget(parent)
{
    ui.setupUi(this);

    taskCollection_ = core::TaskCollection(taskService);

    // Initialize the task collection
    taskCollection_.initialize();

    // Get the tasks data structure
    std::map<std::string, core::Task> tMap = taskCollection_.getTasks();

    // Add each element to the gui
    std::map<std::string, core::Task>::const_iterator it = tMap.begin();
    for (; it != tMap.end(); it++) {
        TaskWidget *tw = new TaskWidget(it->first, it->second.getContent(), this);
        tw->displayContent();
        ui.tasksVerticalLayout->addWidget(tw);
    }
    this->setLayout(ui.tasksVerticalLayout);
}

MainWindow::~MainWindow()
{
}

// //----    SLOTS    ----// //

void MainWindow::synchTaskSlot(std::string id)
{
    // TODO: complete operation and use sender object to call synchDone()
    // method
//    TaskWidget *sender = (TaskWidget *)QObject::sender();
//    taskCollection_.synchTask(id, sender);

}

void MainWindow::deleteTaskSlot(std::string id)
{
    // TODO: complete operation and use sender object to call deleteDone()
    // method
//    TaskWidget *sender = (TaskWidget *)QObject::sender();
//    taskCollection_.deleteTask(id);
}

#include "MainWindow.h"

#include <map>
#include <QLineEdit>
#include "Task.h"

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
        QLineEdit *lineEdit = new QLineEdit(
                QString::fromStdString(it->second.getContent()), this);
        ui.tasksVerticalLayout->addWidget(lineEdit);
    }
    this->setLayout(ui.tasksVerticalLayout);
}

MainWindow::~MainWindow()
{

}

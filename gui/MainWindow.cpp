#include "MainWindow.h"

#include <map>
#include <QLineEdit>
#include "Task.h"
#include "ThreadException.h"
#include <QMessageBox>
#include "SynchMutexException.h"

MainWindow::MainWindow(core::TaskService *taskService, QWidget *parent)
: QWidget(parent)
{
    ui.setupUi(this);

    // Initialize the mutex for the taskCollection
    pthread_mutex_init(&synchMutex_, NULL);

    taskCollection_ = core::TaskCollection(taskService);

    // Initialize the task collection
    taskCollection_.initialize();

    // Get the tasks data structure
    std::map<std::string, core::Task> tMap = taskCollection_.getTasks();

    // Add each element to the gui
    std::map<std::string, core::Task>::const_iterator it = tMap.begin();
    for (; it != tMap.end(); it++) {

        // Create a new TaskWidget element
        TaskWidget *tw = new TaskWidget(it->first, it->second.getContent(), this);

        // Display the task content in the TaskWidget
        tw->displayContent();

        // Connect the TaskWidget signals to the MainWindow slots
        connect(tw, SIGNAL(synchTaskSignal(std::string &)), this, SLOT(synchTaskSlot(std::string &)));
        connect(tw, SIGNAL(deleteTaskSignal(std::string &)), this, SLOT(deleteTaskSlot(std::string &)));

        // Add the TaskWidget to the layout
        ui.tasksVerticalLayout->addWidget(tw);
    }

    this->setLayout(ui.tasksVerticalLayout);
}

core::TaskCollection &MainWindow::getTaskCollection()
{
    return taskCollection_;
}

void MainWindow::lockTaskCollection()
{
    int ret = pthread_mutex_trylock(&synchMutex_);
    if (ret != 0) {
        // Cannot acquire the lock
        QMessageBox msgBox;
        msgBox.setText(tr("Another operation is in progress, please wait"));
        msgBox.exec();
        throw new SynchMutexException("Cannot acquire the lock to update this task");
    }
}

void MainWindow::unlockTaskCollection()
{
    pthread_mutex_unlock(&synchMutex_);
}

MainWindow::~MainWindow()
{
}

void *synchronizationThreadTask(void *args)
{
    // Get the parameters type
    MainWindow::ThreadParameters *params = reinterpret_cast<MainWindow::ThreadParameters *>(args);

    // Get the class
    MainWindow *mwClass = params->classReference;

    // Get the calling task widget
    TaskWidget *sender = params->callerTask;

    // Get the taskId
    std::string id = params->id;

    // Disable TaskWidget controls (buttons and text line)
    sender->disableControls();

    // Call update
    try {
        mwClass->getTaskCollection().synchTask(id, sender->getContent());
    }
    catch (GenericException &ge) {
        // Display a message box if an exception occurs
        QMessageBox msgBox;
        msgBox.setText(("Error while synching this task"));
        msgBox.setInformativeText(QString::fromStdString(ge.getDescription()));
        msgBox.exec();
    }

//    sleep(5);

    // Enable controls
    sender->enableControls();

    // Notify synch has finished
    sender->synchDone();

    // Realese mutex lock
    mwClass->unlockTaskCollection();

    return NULL;
}

// //----    SLOTS    ----// //

void MainWindow::synchTaskSlot(std::string &id)
{
    // Get the pointer to the signal sender
    TaskWidget *sender = (TaskWidget *)QObject::sender();

    // Get the lock
    try {
        lockTaskCollection();
    }
    catch (SynchMutexException &sme) {
        // Suspend the update operation
        return;
    }

    // Create a new thread parameters data structure
    ThreadParameters *tp = new ThreadParameters;
    tp->classReference = this;
    tp->callerTask = sender;
    tp->id = id;

    // TODO: use qthreads instead of threads and write the same code to handle
    // the error button signal

    // Generate and launch new thread
    pthread_t synchThread;
    int ret = pthread_create(&synchThread, NULL, synchronizationThreadTask, (void *)tp);
    if (ret != 0) {
        throw new ThreadException("Error while creating synch thread");
    }
}

void MainWindow::deleteTaskSlot(std::string &id)
{
    // TODO: complete operation and use sender object to call deleteDone()
    // method
//    TaskWidget *sender = (TaskWidget *)QObject::sender();
//    taskCollection_.deleteTask(id);
}

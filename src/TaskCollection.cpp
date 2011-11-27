/*
 * TaskCollection.cpp
 *
 *  Created on: 16/ott/2011
 *      Author: puller
 */

#include "TaskCollection.h"
#include "exceptions/NotInitializedException.h"

namespace core {

TaskCollection::TaskCollection()
{
    tasks_.clear();
    taskService_ = NULL;
}

TaskCollection::TaskCollection(TaskService *taskService)
{
    taskService_ = taskService;
}

void TaskCollection::initialize()
{
    if (taskService_ == NULL) {
        throw new NotInitializedException("Task service not initialied in task collection object");
    }

    std::vector<Task> tasksVector = taskService_->fetchTasks();

    for (unsigned int i = 0; i < tasksVector.size(); ++i) {
        tasks_[tasksVector[i].getIdentifier()] = tasksVector[i];
    }
}

void TaskCollection::synchTask(std::string &id, std::string &content)
{
    taskService_->updateTask(id, content);
}

TaskCollection::~TaskCollection()
{
    tasks_.clear();
    taskService_ = NULL;
}

} /* namespace core */

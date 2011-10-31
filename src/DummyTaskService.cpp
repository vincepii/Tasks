/*
 * DummyTaskService.cpp
 *
 *  Created on: 31/ott/2011
 *      Author: puller
 */

#include "DummyTaskService.h"

#include <vector>

namespace core {

DummyTaskService::DummyTaskService()
{
    identifiers_ = 0;
    tasks_.clear();
    for (int i = 0; i < 10; i++) {
        Task t;
        std::string id = getIdentifier();
        t.setContent("Task " + id);
        t.setIdentifier(id);
        tasks_[id] = t;
    }
}

std::vector<Task> DummyTaskService::fetchTasks()
{
    std::vector<Task> tasksV;
    std::map<std::string, Task>::const_iterator it = tasks_.begin();
    for (; it != tasks_.end(); it++) {
        tasksV.push_back(it->second);
    }
    return tasksV;
}

std::string DummyTaskService::addTask(const std::string& content)
{
    std::string id = getIdentifier();
    Task t;
    t.setContent(content);
    t.setIdentifier(id);
    tasks_[id] = t;
    return id;
}

void DummyTaskService::updateTask(const std::string& identifier, const std::string& content)
{
    std::map<std::string, Task>::iterator it = tasks_.find(identifier);
    it->second.setContent(content);
    it->second.setChanged(true);
}

void DummyTaskService::deleteTask(const std::string& identifier)
{
    tasks_.erase(identifier);
}


DummyTaskService::~DummyTaskService()
{
}

} /* namespace core */

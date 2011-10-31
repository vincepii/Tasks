/*
 * TaskService.h
 *
 *  Created on: 16/ott/2011
 *      Author: puller
 */

#ifndef TASKSERVICE_H_
#define TASKSERVICE_H_

#include <vector>

#include "Task.h"

namespace core {

/**
 * This class communicates with a task service and uses its APIs to get the
 * tasks.
 * The methods of this class should be executed by a thread which, when finished
 * does a callback.
 */
class TaskService {
public:

    /**
     * Default constructor
     */
    TaskService();

    /**
     * Fetches all tasks from the task service
     * @return The tasks list
     */
    virtual std::vector<Task> fetchTasks() = 0;

    /**
     * Adds a new task and returns the identifier
     * @param content Task content
     * @return Task identifier
     */
    virtual std::string addTask(const std::string& content) = 0;

    /**
     * Updates a single task
     * @param identifier Task identifier
     * @param content Task content
     */
    virtual void updateTask(const std::string& identifier, const std::string& content) = 0;

    /**
     * Deletes a single task
     * @param identifier Task identifier
     */
    virtual void deleteTask(const std::string& identifier) = 0;

    virtual ~TaskService();
};

} /* namespace core */
#endif /* TASKSERVICE_H_ */

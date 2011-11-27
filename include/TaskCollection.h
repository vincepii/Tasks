/*
 * TaskCollection.h
 *
 *  Created on: 16/ott/2011
 *      Author: puller
 */

#ifndef TASKCOLLECTION_H_
#define TASKCOLLECTION_H_

#include <vector>
#include <map>

#include "Task.h"
#include "TaskService.h"

namespace core {

/**
 * This class manages a collection of tasks
 */
class TaskCollection {

    /// The tasks collection data structure
    std::map<std::string, Task> tasks_;

    /// Tasks service object
    TaskService *taskService_;

public:

    /**
     * Default constructor
     */
    TaskCollection();

    /**
     * Constructor
     * @param taskService Task service interfacer object
     */
    TaskCollection(TaskService *taskService);

    /**
     * Initializes the task collection by fetching all tasks from the task
     * service
     */
    void initialize();

    /**
     * Tasks map getter
     * @return Tasks map
     */
    std::map<std::string, Task>& getTasks() {
        return tasks_;
    }

    /**
     * Uses the taskService to synch this task
     * @param id Task Id
     * @param content Task content
     */
    void synchTask(std::string &id, std::string &content);

    virtual ~TaskCollection();
};

} /* namespace core */
#endif /* TASKCOLLECTION_H_ */

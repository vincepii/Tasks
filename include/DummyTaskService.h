/*
 * DummyTaskService.h
 *
 *  Created on: 31/ott/2011
 *      Author: puller
 */

#ifndef DUMMYTASKSERVICE_H_
#define DUMMYTASKSERVICE_H_

#include <stdint.h>
#include <string>
#include <map>
#include <sstream>

#include "TaskService.h"
#include "Task.h"

namespace core {

class DummyTaskService : public TaskService{

    /** Local tasks database */
    std::map<std::string, Task> tasks_;

    /** Simple task identifier counter */
    uint32_t identifiers_;

public:

    /**
     * Default contructor
     */
    DummyTaskService();

    /**
     * Fetches all tasks from the task service
     * @return The tasks list
     */
    virtual std::vector<Task> fetchTasks();

    /**
     * Adds a new task and returns the identifier
     * @param content Task content
     * @return Task identifier
     */
    virtual std::string addTask(const std::string& content);

    /**
     * Updates a single task
     * @param identifier Task identifier
     * @param content Task content
     */
    virtual void updateTask(const std::string& identifier, const std::string& content);

    /**
     * Deletes a single task
     * @param identifier Task identifier
     */
    virtual void deleteTask(const std::string& identifier);

    /**
     * Destructor
     */
    virtual ~DummyTaskService();

private:

    /**
     * Returns next identifier as a string
     * @return Identifier
     */
    std::string getIdentifier()
    {
        std::stringstream ss;
        ss << identifiers_;
        identifiers_++;
        return ss.str();
    }

};

} /* namespace core */
#endif /* DUMMYTASKSERVICE_H_ */

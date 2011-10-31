/*
 * Task.h
 *
 *  Created on: 16/ott/2011
 *      Author: puller
 */

#ifndef TASK_H_
#define TASK_H_

#include <string>

namespace core {

/**
 * This class describes a single task
 */
class Task {

    /// Task unique identifier inside the task service
    std::string identifier_;

    /// Task content
    std::string content_;

    /// Tells if the task content has changed and should be synched
    bool changed_;

public:

    /**
     * Default constructor
     */
    Task();

    /**
     * Task constructor
     *
     * @param identifier Task identifier
     * @param content Task content
     * @param bootstrap Says if this is task has been created by the user or
     * retrieved from the server at initialization
     */
    Task(std::string identifier, std::string content, bool bootstrap);

    /**
     * Content getter
     * @return The task content
     */
    const std::string& getContent() const {
        return content_;
    }

    /**
     * Content setter
     * @param content The task content
     */
    void setContent(const std::string& content) {
        content_ = content;
    }

    /**
     * Identifier getter
     * @return The task identifier
     */
    const std::string& getIdentifier() const {
        return identifier_;
    }

    /**
     * Identifier setter
     * @param identifier The task identifier
     */
    void setIdentifier(const std::string& identifier) {
        identifier_ = identifier;
    }

    /**
     * Returns the current task synch status
     * @return Task synch status
     */
    bool isChanged() const {
        return changed_;
    }

    /**
     * Sets the task synch status
     * @param changed The task synch status
     */
    void setChanged(bool changed) {
        changed_ = changed;
    }

    virtual ~Task();
};

} /* namespace core */
#endif /* TASK_H_ */

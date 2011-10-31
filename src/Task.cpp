/*
 * Task.cpp
 *
 *  Created on: 16/ott/2011
 *      Author: puller
 */

#include "Task.h"

namespace core {

Task::Task() {
    changed_ = false;
    content_.clear();
    identifier_.clear();
}

Task::Task(std::string identifier, std::string content, bool bootstrap) {
    identifier_ = identifier;
    content_ = content;
    if (bootstrap == true) {
        changed_ = false;
    }
    else {
        changed_ = true;
    }
}

Task::~Task() {
    changed_ = false;
    content_.clear();
    identifier_.clear();
}

} /* namespace core */

/*
 * ThreadException.h
 *
 *  Created on: 27/nov/2011
 *      Author: puller
 */

#ifndef THREAD_EXCEPTION_H_
#define THREAD_EXCEPTION_H_

#include "GenericException.h"

class ThreadException : public GenericException
{
public:
    ThreadException() : GenericException() {}

    ThreadException(const std::string& description) : GenericException(description) {}

    virtual ~ThreadException() {}
};



#endif /* THREAD_EXCEPTION_H_ */

/*
 * SynchMutexException.h
 *
 *  Created on: 27/nov/2011
 *      Author: puller
 */

#ifndef SYNCH_MUTEX_EXCEPTION_H_
#define SYNCH_MUTEX_EXCEPTION_H_

#include "GenericException.h"

class SynchMutexException : public GenericException
{
public:
    SynchMutexException() : GenericException() {}

    SynchMutexException(const std::string& description) : GenericException(description) {}

    virtual ~SynchMutexException() {}
};



#endif /* SYNCH_MUTEX_EXCEPTION_H_ */

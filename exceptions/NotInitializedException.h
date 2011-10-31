/*
 * NotInitialized.h
 *
 *  Created on: 16/ott/2011
 *      Author: puller
 */

#ifndef NOTINITIALIZED_H_
#define NOTINITIALIZED_H_

#include "GenericException.h"

class NotInitializedException : public GenericException
{
public:
    NotInitializedException() : GenericException() {}

    NotInitializedException(const std::string& description) : GenericException(description) {}

    virtual ~NotInitializedException() {}
};



#endif /* NOTINITIALIZED_H_ */

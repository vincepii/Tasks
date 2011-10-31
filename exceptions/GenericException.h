/*
 * GenericException.h
 *
 *  Created on: 16/ott/2011
 *      Author: puller
 */

#ifndef GENERICEXCEPTION_H_
#define GENERICEXCEPTION_H_

#include <string>

class GenericException {

    /// Exception description
    std::string description_;

public:

    /**
     * Default constructor
     */
    GenericException() {
        description_.clear();
    }

    /**
     * Constructor
     * @param description Exception description
     */
    GenericException(const std::string& description)
    {
        description_ = description;
    }

    /**
     * Description getter
     * @return Exception description
     */
    virtual const std::string& getDescription() const
    {
        return description_;
    }

    /**
     * Description setter
     * @param description Exception description
     */
    virtual void setDescription(const std::string& description)
    {
        description_ = description;
    }

    virtual ~GenericException()
    {
        description_.clear();
    }

};


#endif /* GENERICEXCEPTION_H_ */

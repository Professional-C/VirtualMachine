//
//  Exceptions.cpp
//  src
//
//  Created by Sydney Nguyen on 3/31/21.
//

#include "Exceptions.h"
#include <stdio.h>

FatalException::FatalException(int error)
: errorCode(error) {}

NonFatalException::NonFatalException(int error)
: errorCode(error) {}


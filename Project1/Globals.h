#ifndef __GLOBALS_H__
#define __GLOBALS_H__

#pragma once

enum class update_status
{
	UPDATE_CONTINUE = 1,
	UPDATE_STOP,
	UPDATE_ERROR
};

#define NULL 0
typedef unsigned int uint;

// Deletes a buffer
#define RELEASE( x ) \
    {                        \
    if( x != NULL )        \
	    {                      \
      delete x;            \
	  x = NULL;              \
	    }                      \
    }

#define APP_NAME "ProjectVoid v0.0.01"

#endif //GLOBALS_H

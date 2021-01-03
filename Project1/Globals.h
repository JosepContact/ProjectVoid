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

struct Position
{
	Position(int aX, int aY) : x(aX), y(aY) {};
	int x, y;
};

#define APP_NAME "ProjectVoid v0.0.01"

// Resources
#define XML_RESOURCES_PATH "data/resources.xml"
#define XML_RESOURCES_NAME "Resources"

#endif //GLOBALS_H

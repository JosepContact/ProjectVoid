#ifndef __CMODULEFILESYSTEM_H__
#define __CMODULEFILESYSTEM_H__
#pragma once

#include "pugixml-1.10\src\pugixml.hpp"
#include "CModule.h"


class CModuleFileSystem : public CModule
{
public:

	CModuleFileSystem(bool start_enabled = true);

	// Destructor
	virtual ~CModuleFileSystem();

	// Starts The FileSystem Module
	bool Start();

	// Called before quitting
	bool CleanUp();

	uint Load(const char* path, char** bufer) const;

	std::string CreateFolder(const char* path, const char* folder_name);

	pugi::xml_node LoadXML(const char* filename, const char* child, pugi::xml_document& file) const;

private:

};

#endif // __FILESYSTEM_H__
#include <windows.h>
#include <fstream>

#include "CModuleFileSystem.h"
#include "App.h"
#include "CModuleFileSystem.h"
#include "PhysFS/include/physfs.h"

#pragma comment( lib, "PhysFS/libx86/physfs.lib" )

CModuleFileSystem::CModuleFileSystem(bool start_enabled)
{
}


CModuleFileSystem::~CModuleFileSystem()
{
}

bool CModuleFileSystem::CleanUp()
{
	return true;
}

bool CModuleFileSystem::Start()
{
	//CreateFolder("", "Concepts");
	return true;
}

uint CModuleFileSystem::Load(const char* path, char** buffer) const
{
	unsigned int ret = 0;

	if (path == nullptr)
		return ret;

	//ofstream;
	FILE* load_file = fopen(path, "rb");

	if (load_file)
	{
		int size = 0;

		std::ifstream in(path, std::ifstream::ate | std::ifstream::binary);
		size = in.tellg();

		if (size > 0)
		{
			*buffer = new char[(unsigned int)size];
			unsigned int read = (unsigned int)fread(*buffer, sizeof(char), size, load_file);
			if (read != size)
			{
				LOG("ERROR while reading file:\n\t%s \n", path);
				if (*buffer != nullptr)
					RELEASE(*buffer);
			}
			else
			{
				ret = (unsigned int)read;
			}
		}
		if (fclose(load_file) != 0)
		{
			LOG("ERROR while opening file:\n\t%s\n\t%s \n", path, strerror(errno));
		}
	}
	else
	{
		LOG("ERROR while opening file:\n\t%s\n\t%s \n", path, strerror(errno));
	}


	return ret;
}

std::string CModuleFileSystem::CreateFolder(const char* path, const char* folder_name)
{
	std::string ret;

	std::string fldrPath = path;
	if (fldrPath.length() > 0 && fldrPath[fldrPath.length() - 1] != '\\')
	{
		fldrPath += '\\';
	}
	fldrPath += folder_name;

	if (CreateDirectory(fldrPath.c_str(), NULL) == 0)
	{
		LOG("ERROR Creating Directory %s[%s] \n", folder_name, strerror(errno));
		return ret;
	}

	ret = fldrPath + '\\';

	return ret;
}

pugi::xml_node CModuleFileSystem::LoadXML(const char* filename, const char* child, pugi::xml_document& file) const
{
	pugi::xml_node ret;

	char* buf = NULL;
	unsigned int size = Load(filename, &buf);
	pugi::xml_parse_result result = file.load_buffer(buf, size);
	RELEASE(buf);

	if (result == NULL)
	{
		LOG("Could not load map xml file. pugi error: %s \n", result.description());
	}
	else
		ret = file.child(child);

	/*if (result != NULL)
	{
		ret = file.child(child);
	}*/

	return ret;
}
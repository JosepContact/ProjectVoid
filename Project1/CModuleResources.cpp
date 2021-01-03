#include "CModuleResources.h"
#include "App.h"
#include "CModuleFileSystem.h"

CModuleResources::CModuleResources(const std::string& aModuleName, bool aEnabled)
{
}

CModuleResources::~CModuleResources()
{
}

bool CModuleResources::Start()
{
	//-- Resources ----
	pugi::xml_document	ResourceFile;
	pugi::xml_node		Resources;

	Resources = app->mpModuleFileSystem->LoadXML(XML_RESOURCES_PATH, XML_RESOURCES_NAME, ResourceFile);

	if (!Resources.empty())
	{
		for (pugi::xml_node Resource = Resources.child("Resource"); Resource; Resource = Resource.next_sibling("Resource"))
		{
			std::string Name = Resource.child("Name").attribute("value").as_string();
			SDL_Rect Rect = { 0, 0, Resource.child("Width").attribute("value").as_uint(), Resource.child("Height").attribute("value").as_uint() };
			std::string Path = Resource.child("Path").attribute("value").as_string();
			CResource* pResource = new CResource(Name, Rect, Path);
			pResource->Init();
			mpResourcesList.push_back(pResource);
		}
	}
	else
	{
		LOG("Error loading %s.", XML_RESOURCES_PATH);
	}

	return true;
}

bool CModuleResources::CleanUp()
{
	for (auto& Resource : mpResourcesList)
	{
		Resource->CleanUp();
		RELEASE(Resource);
	}

	return true;
}

update_status CModuleResources::Update()
{
	return update_status::UPDATE_CONTINUE;
}

#include "CModule.h"

CModule::CModule(const std::string& aName, bool aStartEnabled) :
	mModuleName(aName),
	mEnabled(aStartEnabled)
{
}

CModule::~CModule()
{
}

bool CModule::Start()
{
	return true;
}


bool CModule::CleanUp()
{
	return true;
}

update_status CModule::Update()
{
	return UPDATE_CONTINUE;
}

const std::string CModule::GetModuleName() const
{
	return mModuleName;
}

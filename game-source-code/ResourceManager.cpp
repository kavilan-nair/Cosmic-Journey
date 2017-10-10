#include "ResourceManager.h"

ResourceManager::ResourceManager(EntityType entityID, std::string resourcePath)
{
	_resourcePath = resourcePath;
	_entityType = entityID;
}

ResourceManager::~ResourceManager()
{
}

EntityType ResourceManager::getEntityID()
{
	return _entityType;
}

string ResourceManager::getResourcePath()
{
	return _resourcePath;
}
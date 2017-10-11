#include "ResourceManager.h"

ResourceManager::ResourceManager(EntityType entityID, std::string resourcePath) : _resourcePath(resourcePath), _entityType(entityID)
{
}

ResourceManager::~ResourceManager()
{
}

EntityType ResourceManager::getEntityID() const
{
	return _entityType;
}

string ResourceManager::getResourcePath() const
{
	return _resourcePath;
}
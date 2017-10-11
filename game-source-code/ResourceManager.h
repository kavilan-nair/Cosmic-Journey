#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include "EntityType.h"
#include "string"
using std::string;

class ResourceManager
{
public:
	ResourceManager(EntityType entityID, std::string resourcePath);
	~ResourceManager();
	EntityType getEntityID() const;
	string getResourcePath() const;
private:
	string _resourcePath;
	EntityType _entityType;	
};

#endif // RESOURCEMANAGER_H
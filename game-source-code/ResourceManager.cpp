#include "ResourceManager.h"


ResourceManager::ResourceManager()
{
}


ResourceManager::ResourceManager(ResourceType resourceType, std::string resourcePath) : _resourcePath(resourcePath), _resourceType(resourceType)
{
}

ResourceManager::~ResourceManager()
{
}

ResourceType ResourceManager::getResourceType() const
{
    return _resourceType;
}

string ResourceManager::getResourcePath() const
{
    return _resourcePath;
}

vector<ResourceManager> ResourceManager::getResourceInfo()
{
    vector<string> paths = {"Resources/PlayerAlt.png", 
                                "Resources/Enemy.png", 
                                "Resources/Satellite.png", 
                                "Resources/LaserGenerator.png",
                                "Resources/PlayerBullet.png",
                                "Resources/EnemyBullet.png",
                                "Resources/LaserField.png",
                                "Resources/Asteroid.png",
                                "Resources/Background.png",
                                "Resources/Font.ttf"};
    
    vector<ResourceManager> resources;
                                
    for(unsigned int i = 0; i != paths.size(); i++)
    {
        ResourceManager resource{static_cast<ResourceType>(i), paths.at(i)};
        resources.push_back(resource);
    }
    
    return resources;
}
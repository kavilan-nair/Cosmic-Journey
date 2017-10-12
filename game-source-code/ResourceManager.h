#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include "EntityType.h"
#include <string>
using std::string;

/**
* ResourceManager class - Data class containing an EntityType and string to the resource png.
*/

class ResourceManager
{
    public:
        /**
        * @brief Parameterized constructor. Creates a ResourceManager object.
        */
        ResourceManager(EntityType entityID, std::string resourcePath);
        /**
        * @brief Default destructor. Destroys ResourceManager object.
        */
        ~ResourceManager();
        /**
        * @brief Returns the EntityID related to the ResourceManager.
        * @returns enum of strongly typed EntityType enum.
        */
        EntityType getEntityID() const;
        /**
        * @brief Returns the location on the disk related to the resource. 
        * @returns string with path to resource.png.
        */
        string getResourcePath() const;
        
    private:
        string _resourcePath;
        EntityType _entityType;	
};

#endif // RESOURCEMANAGER_H
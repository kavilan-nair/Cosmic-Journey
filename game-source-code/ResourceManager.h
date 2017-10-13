#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include "ResourceType.h"
#include <string>
using std::string;
#include <vector>
using std::vector;

/**
* ResourceManager class - Data class containing a ResourceType and the path to resource
*/

class ResourceManager
{
public:
        /**
        * @brief Default constructor. Creates a ResourceManager object.
        */
        ResourceManager();
        /**
        * @brief Parameterized constructor. Creates a ResourceManager object.
        */
        ResourceManager(ResourceType resourceType, std::string resourcePath);
        /**
        * @brief Default destructor. Destroys ResourceManager object.
        */
        ~ResourceManager();
        /**
        * @brief Returns the ResourceType related to the ResourceManager.
        * @returns enum of strongly typed ResourceType enum.
        */
        ResourceType getResourceType() const;
        /**
        * @brief Returns the location on the disk related to the resource. 
        * @returns string with path to resource.png.
        */
        string getResourcePath() const;
        /**
        * @brief Returns a vector of ResourceManager containing all the resource infor for the project
        * @returns vector of type ResourceManager
        */
        vector<ResourceManager> getResourceInfo();
        
    private:
        string _resourcePath;
        ResourceType _resourceType;	
};

#endif // RESOURCEMANAGER_H
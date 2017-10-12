#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include "EntityType.h"
#include <string>
using std::string;

/**
* ResourceManager class - Data class containing an EntityType and string to the resource png
*/

class ResourceManager
{
	public:
		/**
		* Parameterized constructor. Creates a ResourceManager object
		*/
		ResourceManager(EntityType entityID, std::string resourcePath);
		/**
		* Default destructor. Deletes ResourceManager object
		*/
		~ResourceManager();
		/**
		* Returns the EntityID related to the ResourceManager
		* @returns _entityType of type EntityType
		*/
		EntityType getEntityID() const;
		/**
		* Returns the path related to the resource 
		* @returns _resourcePath of type string
		*/
		string getResourcePath() const;
		
	private:
		string _resourcePath;
		EntityType _entityType;	
};

#endif // RESOURCEMANAGER_H
#include "ResourceManager.h"
#include "EntityType.h"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

TEST_CASE("Resource Manager resource path and entity type set are retrieved")
{
    
    ResourceType resourceType = ResourceType::PLAYER;
    string resourcePath = "Resources/PlayerAlt.png";
    ResourceManager resourceManager{resourceType, resourcePath };
    
    CHECK(resourceManager.getResourceType() == resourceType);
    CHECK(resourceManager.getResourcePath() == resourcePath);
}
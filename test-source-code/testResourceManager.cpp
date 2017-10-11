#include "ResourceManager.h"
#include "EntityType.h"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

TEST_CASE("Resource Manager resource path and entity type set and retrieved")
{
    
    EntityType entityType = EntityType::PLAYER;
    string resourcePath = "Resources/PlayerAlt.png";
    ResourceManager resourceManager{entityType, resourcePath };
    
    CHECK(resourceManager.getEntityID() == entityType);
    CHECK(resourceManager.getResourcePath() == resourcePath);
}


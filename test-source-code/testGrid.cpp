#include "Grid.h"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

TEST_CASE("Check grid width and height is set correctly")
{
    int width = 800;
    int height = 600;
    Grid grid{width, height};
    
    CHECK(grid.getWidth() == width);
    CHECK(grid.getHeight() == height);
}

TEST_CASE("Check grid center and radius properties")
{
    int width = 800;
    int height = 600;
    Grid grid{width, height};
    
    int centerX = width/2;
    int centerY = height/2;
    int radius = (height/2)*0.95;
    
    CHECK(grid.getCenterX() == centerX);
    CHECK(grid.getCenterY() == centerY);
    CHECK(grid.getRadius() == radius);
}
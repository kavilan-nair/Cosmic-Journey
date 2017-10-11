#include "Position.h"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

TEST_CASE("Position x and y can be set and retrieved")
{
    Position testPosition{};
    int x = 5;
    int y = 6;
    testPosition.setXpos(x);
    testPosition.setYpos(y);
    
    CHECK(testPosition.getXpos() == x);
    CHECK(testPosition.getYpos() == y);
}

TEST_CASE("Initial position x and y can be set and retrieved")
{
    Position testPosition{};
    int x = 5;
    int y = 6;
    testPosition.setXposInitial(x);
    testPosition.setYposInitial(y);
    
    CHECK(testPosition.getXposInitial() == x);
    CHECK(testPosition.getYposInitial() == y);
}

TEST_CASE("Initial position x and y can be set and retrieved")
{
    Position testPosition{};
    int radius = 100;
    int angle = 45;
    testPosition.setRadius(radius);
    testPosition.setAngle(angle);
    
    CHECK(testPosition.getRadius() == radius);
    CHECK(testPosition.getAngle() == angle);
}


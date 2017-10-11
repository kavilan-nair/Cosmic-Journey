#include "HighScoreManager.h"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

TEST_CASE("Check HighScoreManager can get and set HighScore ")
{
    HighScoreManager highScoreManager{};
    int highScore = 9999;
    highScoreManager.setHighScore(highScore);
    
    CHECK(highScore == highScoreManager.getHighScore());
}

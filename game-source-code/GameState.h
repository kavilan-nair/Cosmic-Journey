#ifndef GAMESTATE_H
#define GAMESTATE_H

/**
* GameState is a strongly typed enum used to by Logic to identify what state the game is
*/
enum class GameState
{
    SPLASHSCREEN = 0,
    ACTIVE,
    GAME_OVER,
    GAME_WON
};

#endif // GAMESTATE_H
#ifndef GAMEOVERSCREEN_H
#define GAMEOVERSCREEN_H

#include <SFML/Graphics.hpp>

/**
* GameOverScreen class - Uses the SFML library to display that the player has won and shows a score summary
*/
class GameOverScreen
{
    public:
        /**
        * @brief Default constructor. Creates GameOverScreen object
        */
        GameOverScreen();
        /**
        * @brief Displays the GameOverScreen
        * @param renderWindow is of type sf::RenderWindow 
        */
        void show(sf::RenderWindow& renderWindow, const int& score, const& highscore);
        /**
        * @brief Default destructor. Deletes GameOverScreen object
        */
        ~GameOverScreen();

    private:
        sf::Texture _gameOverTexture;
        sf::Font font;
};

#endif
#ifndef WINNERSCREEN_H
#define WINNERSCREEN_H

#include <SFML/Graphics.hpp>
#include <string>

/**
* WinnerScreen class - Uses the SFML library to display that the player has won and shows a score summary.
*/
class WinnerScreen
{
    public:
        /**
        * @brief Default constructor. Creates WinnerScreen object.
        */
        WinnerScreen();
        /**
        * @brief Displays the WinnerScreen.
        * @param renderWindow is of type sf::RenderWindow which holds the window to render on the monitor. 
        */
        void show(sf::RenderWindow& renderWindow, const int& score, const& highscore);
        /**
        * @brief Default destructor. Creates WinnerScreen object.
        */
        ~WinnerScreen();
        
    private:
        sf::Texture _winnerTexture;
        sf::Font font;
};

#endif //WINNERSCREEN_H
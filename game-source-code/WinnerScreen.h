#ifndef WINNERSCREEN_H
#define WINNERSCREEN_H

#include <SFML/Graphics.hpp>
#include <string>

/**
* WinnerScreen class - Uses the SFML library to display that the player has won and shows a score summary
* Inherits from IMovingEntity class.
*/
class WinnerScreen
{
    public:
        /**
	    * Default constructor. Creates WinnerScreen object
	    */
        WinnerScreen();
        /**
        * Displays the WinnerScreen
        * @param renderWindow is of type sf::RenderWindow 
	    */
        void show(sf::RenderWindow& renderWindow, const int& score, const& highscore);
        /**
	    * Default destructor. Creates SplashScreen object
	    */
        ~WinnerScreen();
private:
	sf::Texture _winnerTexture;
	sf::Font font;
};

#endif //WINNERSCREEN_H
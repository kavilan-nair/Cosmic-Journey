#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include <SFML/Graphics.hpp>


/**
* SplashScreen class - Uses the SFML library to display the game title and playing instruction
* Inherits from IMovingEntity class.
*/
class SplashScreen
{
    public:
        /**
	    * Default constructor. Creates SplashScreen object
	    */
        SplashScreen();
        /**
        * Displays the SplashScreen
        * @param renderWindow is of type sf::RenderWindow 
	    */
        void show(sf::RenderWindow& renderWindow);
        /**
	    * Default destructor. Creates SplashScreen object
	    */
        ~SplashScreen();
private:
	sf::Texture _splashTexture;
	sf::Font font;
};

#endif //SPLASHSCREEN_H
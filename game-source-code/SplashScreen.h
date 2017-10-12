#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include <SFML/Graphics.hpp>

/**
* SplashScreen class - Uses the SFML library to display the game title and playing instructions.
*/
class SplashScreen
{
    public:
        /**
        * @brief Default constructor. Creates SplashScreen object.
        */
        SplashScreen();
        /**
        * @brief Function that displays the SplashScreen window.
        * @param renderWindow is of type sf::RenderWindow.
        */
        void show(sf::RenderWindow& renderWindow);
        /**
        * @brief Default destructor. Destroys SplashScreen object.
        */
        ~SplashScreen();
    
    private:
        sf::Texture _splashTexture;
        sf::Font font;
};

#endif //SPLASHSCREEN_H
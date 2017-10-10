#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include <SFML/Graphics.hpp>

class SplashScreen
{
    public:
        SplashScreen();
        void show(sf::RenderWindow& renderWindow);
        ~SplashScreen();
private:
	sf::Texture _splashTexture;
	sf::Font font;
};

#endif //SPLASHSCREEN_H
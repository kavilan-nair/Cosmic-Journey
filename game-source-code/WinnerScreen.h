#ifndef WINNERSCREEN_H
#define WINNERSCREEN_H

#include <SFML/Graphics.hpp>

class WinnerScreen
{
    public:
        WinnerScreen();
        void show(sf::RenderWindow& renderWindow);
        ~WinnerScreen();
private:
	sf::Texture _winnerTexture;
	sf::Font font;
};




#endif
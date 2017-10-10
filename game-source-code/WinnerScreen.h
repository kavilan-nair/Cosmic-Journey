#ifndef WINNERSCREEN_H
#define WINNERSCREEN_H

#include <SFML/Graphics.hpp>
#include <string>

class WinnerScreen
{
    public:
        WinnerScreen();
        void show(sf::RenderWindow& renderWindow, const int& score, const& highscore);
        ~WinnerScreen();
private:
	sf::Texture _winnerTexture;
	sf::Font font;
};

#endif //WINNERSCREEN_H
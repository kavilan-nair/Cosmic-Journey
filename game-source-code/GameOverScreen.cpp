#include "GameOverScreen.h"
#include <string>

GameOverScreen::GameOverScreen()
{
    _gameOverTexture.loadFromFile("Resources/splash.png");
}

void GameOverScreen::show(sf::RenderWindow& renderWindow)
{
	sf::Sprite background;
	background.setTexture(_gameOverTexture);
	
	font.loadFromFile("Resources/Agency_FB.ttf");
	std::string gameOverTitle = "Game Over :(";
	sf::Text title(gameOverTitle, font);
	title.setCharacterSize(58);
	title.setPosition(renderWindow.getSize().x/4,renderWindow.getSize().y/4);
	title.setStyle(sf::Text::Bold);
	title.setColor(sf::Color::Yellow);
	
	std::string gameOverControls = "Press Enter key to play again";
								 
	sf::Text controls(gameOverControls,font);
	controls.setCharacterSize(25);
	controls.setPosition(renderWindow.getSize().x/4,renderWindow.getSize().y/2 - renderWindow.getSize().y/10);
	controls.setStyle(sf::Text::Bold);
	controls.setColor(sf::Color::Yellow);
	
	renderWindow.draw(background);
	renderWindow.draw(controls);
	renderWindow.draw(title);
    renderWindow.display();
    
    sf::Event event;
    while(true)
    {
        while (renderWindow.pollEvent(event))              
        {
			if(event.key.code == sf::Keyboard::Return){return;}
        }
    }
}

GameOverScreen::~GameOverScreen()
{

}
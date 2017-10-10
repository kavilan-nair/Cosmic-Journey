#include "GameOverScreen.h"
#include <string>

GameOverScreen::GameOverScreen()
{
    _gameOverTexture.loadFromFile("Resources/Background.png");
}

void GameOverScreen::show(sf::RenderWindow& renderWindow, const int& score, const& highscore)
{
	sf::Sprite background;
	background.setTexture(_gameOverTexture);
	
	font.loadFromFile("Resources/Font.ttf");
	std::string gameOverTitle = "Game Over";
	sf::Text title(gameOverTitle, font);
	title.setCharacterSize(58);
	title.setPosition(renderWindow.getSize().x/3,renderWindow.getSize().y/4);
	title.setStyle(sf::Text::Bold);
	title.setColor(sf::Color::Yellow);
	
	std::string gameOverControls = "Press Enter key to play again";
								 
	sf::Text controls(gameOverControls,font);
	controls.setCharacterSize(25);
	controls.setPosition(renderWindow.getSize().x/3,renderWindow.getSize().y/2 + 100);
	controls.setStyle(sf::Text::Bold);
	controls.setColor(sf::Color::Yellow);
    
    std::string yourScore = "You scored: " + std::to_string(score); 
    sf::Text sfScore(yourScore, font);
    sfScore.setCharacterSize(25);
    sfScore.setPosition(renderWindow.getSize().x/3,renderWindow.getSize().y/2 - 50);
    sfScore.setStyle(sf::Text::Bold);
    sfScore.setColor(sf::Color::Yellow);
    
    std::string highscoreText = "Highscore: " + std::to_string(highscore); 
    sf::Text sfHighScore(highscoreText, font);
    sfHighScore.setCharacterSize(25);
    sfHighScore.setPosition(renderWindow.getSize().x/3,renderWindow.getSize().y/2);
    sfHighScore.setStyle(sf::Text::Bold);
    sfHighScore.setColor(sf::Color::Yellow);
    
	renderWindow.draw(background);
	renderWindow.draw(controls);
	renderWindow.draw(title);
    renderWindow.draw(sfHighScore);
    renderWindow.draw(sfScore);
    renderWindow.display();
    
    sf::Event event;
    while(true)
    {
        while (renderWindow.pollEvent(event))              
        {
			if(event.key.code == sf::Keyboard::Return)
            {
                renderWindow.close();
                return;
            }
        }
    }
}

GameOverScreen::~GameOverScreen()
{

}
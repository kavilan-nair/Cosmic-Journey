#include "SplashScreen.h"
#include <string>

SplashScreen::SplashScreen()
{
	_splashTexture.loadFromFile("Resources/splash.png");
}

void SplashScreen::show(sf::RenderWindow& renderWindow)
{
	sf::Sprite background;
	background.setTexture(_splashTexture);
	
	font.loadFromFile("Resources/Agency_FB.ttf");
	std::string splashTitle = "Shape Space Battle!";
	sf::Text title(splashTitle, font);
	title.setCharacterSize(58);
	title.setPosition(renderWindow.getSize().x/4,renderWindow.getSize().y/4);
	title.setStyle(sf::Text::Bold);
	title.setColor(sf::Color::Yellow);
	
	std::string splashControls = "Controls"
								 "\n -Left arrow key moves clockwise"
								 "\n -Right arrow key moves anticlockwise"
								 "\n -Space key fires glorious cosmic energy"
								 "\n \n Press Home key to continue...";
								 
	sf::Text controls(splashControls,font);
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

SplashScreen::~SplashScreen()
{

}
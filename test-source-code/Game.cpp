#include "Game.h"
#include "GameWindowProperties.h"
#include "Position.h"
#include "Player.h"
#include "SplashScreen.h"
#include <SFML/Graphics.hpp>
#include <math.h>
#include <ctime>
#include <cmath>
#include <vector>

#include <iostream>


const auto PI = 3.14159265358979323846;
const sf::Time Game::TimePerFrame = sf::seconds(1.f/60.f);
sf::VideoMode _screenDimensions = sf::VideoMode::getDesktopMode();

Game::Game() : _window(sf::VideoMode(_screenDimensions), "Software II Project",sf::Style::Fullscreen), _player(), _isMovingClockwise(false), _isMovingAntiClockwise(false)
{    
        //SplashScreen splashscreen;
        //splashscreen.show(_window);
        
        _window.setVerticalSyncEnabled(true);
        GameWindowProperties gameWindowProperties = GameWindowProperties(_window.getSize().x, _window.getSize().y);
        _player = Player(gameWindowProperties);          
        _texture.loadFromFile("Resources/spaceship.png");
        _playerShipSprite.setTexture(_texture);
        _playerShipSprite.setScale(0.15f, 0.15f);
        _playerShipSprite.setPosition(_player.getPosition().getX(), _player.getPosition().getX());

}

void Game::run()
{
        sf::Clock clock;
        sf::Time timeSinceLastUpdate = sf::Time::Zero;
        while (_window.isOpen())
        {
                processEvents();
                timeSinceLastUpdate += clock.restart();
                while (timeSinceLastUpdate > TimePerFrame)
                {
                        timeSinceLastUpdate -= TimePerFrame;
                        processEvents();
                        update(TimePerFrame);
                }
                render();
        }
}

void Game::processEvents()
{
	sf::Event event;
	while (_window.pollEvent(event))
	{
		switch (event.type)
		{
			case sf::Event::KeyPressed:
				handlePlayerInput(event.key.code, true);
				break;

			case sf::Event::KeyReleased:
				handlePlayerInput(event.key.code, false);
				break;

			case sf::Event::Closed:
				_window.close();
				break;
		}
	}
}

void Game::update(sf::Time deltaTime)
{
    if (_isMovingClockwise)        
        _player.moveClockwise();
        
    if (_isMovingAntiClockwise)
        _player.moveAntiClockwise();
        
    _playerShipSprite.setRotation(_player.getPosition().getAngle()*-5);
    _playerShipSprite.setPosition(_player.getPosition().getX(), _player.getPosition().getY());
}

void Game::render()
{
        _window.clear();
       
        sf::Texture backgroundImage;
        backgroundImage.loadFromFile("Resources/background.png");
        sf::Sprite background(backgroundImage);
        _window.draw(background);
        _window.draw(_playerShipSprite);        
        _window.display();
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{	
	if (key == sf::Keyboard::Right)
		_isMovingClockwise = isPressed;
	else if (key == sf::Keyboard::Left)
		_isMovingAntiClockwise = isPressed;
}
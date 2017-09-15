#include "Game.h"
#include "GameWindowProperties.h"
#include "Position.h"
#include "Player.h"
#include <SFML/Graphics.hpp>
#include <math.h>
#include <ctime>

#include <iostream>


const auto PI = 3.14159265358979323846;
const sf::Time Game::TimePerFrame = sf::seconds(1.f/60.f);
//This here is terrible, not sure where to put it
//auto xPosition = 0;
//auto yPosition = 0;
//int angle = 0;
//double theta = 0;
auto originFix = PI/2;
auto radiusFactor = 0.0000;



Game::Game() : _window(sf::VideoMode(640, 480), "Software II Project"), _playerShip() , _player(), _isMovingClockwise(false), _isMovingAntiClockwise(false)
{    
        _window.setVerticalSyncEnabled(true);
        GameWindowProperties gameWindowProperties = GameWindowProperties(_window.getSize().x, _window.getSize().y);
        _player = Player(gameWindowProperties);   
       
        
        sf::Vector2f blockSize(10, 10);
        _playerShip.setSize(blockSize);
        _playerShip.setFillColor(sf::Color::Green);
        
        _playerShip.setPosition(_player.getPosition().getX(), _player.getPosition().getX());
        
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
                
            default:
                break;
		}
	}
}

void Game::update(sf::Time deltaTime)
{
    if (_isMovingClockwise)
    {
        
        _player.moveClockwise();
        _playerShip.rotate(-1*_player.getPosition().getAngle()/5);

    }
        
    if (_isMovingAntiClockwise)
    {
        _player.moveAntiClockwise();
        _playerShip.rotate(_player.getPosition().getAngle()/5);
    }
    
   
    _playerShip.setPosition(_player.getPosition().getX(), _player.getPosition().getY());
    
      //  _player.setPosition(xPosition, yPosition);
   //_player.setPosition(xPosition * deltaTime.asSeconds(), yPosition * deltaTime.asSeconds());
}

void Game::render()
{
        _window.clear();
       
        sf::Texture backgroundImage;
        backgroundImage.loadFromFile("Resources/SpaceA.png");
        sf::Sprite background(backgroundImage);
        _window.draw(background);
        _window.draw(_playerShip);
        
        _window.display();
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{	
	if (key == sf::Keyboard::Right)
		_isMovingClockwise = isPressed;
	else if (key == sf::Keyboard::Left)
		_isMovingAntiClockwise = isPressed;
}
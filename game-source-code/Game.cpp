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
#include "enemy.h"
#include <iostream>


const auto PI = 3.14159265358979323846;
const sf::Time Game::TimePerFrame = sf::seconds(1.f/60.f);
sf::VideoMode _screenDimensions = sf::VideoMode::getDesktopMode();

Game::Game() : _window(sf::VideoMode(_screenDimensions), "Software II Project",sf::Style::Fullscreen), _player(), _enemy(), _isMovingClockwise(false), _isMovingAntiClockwise(false)
{    
        
        _window.setVerticalSyncEnabled(true);
        GameWindowProperties gameWindowProperties = GameWindowProperties(_window.getSize().x, _window.getSize().y);
        _player = Player(gameWindowProperties); 
		_enemy = Enemy(gameWindowProperties);
		
        _texturePlayer.loadFromFile("Resources/spaceship.png");
		_textureEnemy.loadFromFile("Resources/Enemy.png");
		
        _playerShipSprite.setTexture(_texturePlayer);
		auto playerCenterX = _texturePlayer.getSize().x*0.5f;
		auto playerCenterY = _texturePlayer.getSize().y*0.5f;
		_playerShipSprite.setOrigin(playerCenterX, playerCenterY);
		_playerShipSprite.setScale(0.10f, 0.10f);
        _playerShipSprite.setPosition(_player.getPosition().getX(), _player.getPosition().getX());

		_enemyShipSprite.setTexture(_textureEnemy);
		auto enemyCenterX = _textureEnemy.getSize().x*0.5f;
		auto enemyCenterY = _textureEnemy.getSize().y*0.5f;
		_enemyShipSprite.setOrigin(enemyCenterX, enemyCenterY);
        _enemyShipSprite.setScale(0.10f, 0.10f);
        _enemyShipSprite.setPosition(_enemy.getPositionX(), _enemy.getPositionY());
		cout << _enemyShipSprite.getPosition().x << ";" << _enemyShipSprite.getPosition().y << endl;
}

void Game::run()
{
	int count = 0;
		SplashScreen splashscreen;
		splashscreen.show(_window);
	
		
	
        sf::Clock clock;
        sf::Time timeSinceLastUpdate = sf::Time::Zero;
        while (_window.isOpen())
        {
                processInputEvents();
				processAI();
				//process events is for input, need a process for AI
                timeSinceLastUpdate += clock.restart();
                while (timeSinceLastUpdate > TimePerFrame)
                {
                        timeSinceLastUpdate -= TimePerFrame;
                        processInputEvents();
                        update(TimePerFrame);
                }
				count++;
				std::cout << "I am going to render now " << count << std::endl;
                render();
        }
}

void Game::processAI()
{
	if(_enemy.isAlive())
	{
		_enemy.move();
		_enemyShipSprite.setPosition(_enemy.getPositionX(),_enemy.getPositionY());
	}
}

void Game::processInputEvents()
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
        backgroundImage.loadFromFile("Resources/Space.png");
        sf::Sprite background(backgroundImage);
        _window.draw(background);
        _window.draw(_playerShipSprite); 
		_window.draw(_enemyShipSprite);
        _window.display();
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{	
	if (key == sf::Keyboard::Right)
		_isMovingClockwise = isPressed;
	else if (key == sf::Keyboard::Left)
		_isMovingAntiClockwise = isPressed;
}
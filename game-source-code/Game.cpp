#include <math.h>
#include <ctime>
#include <cmath>
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "GameWindowProperties.h"
#include "Position.h"
#include "Player.h"
#include "SplashScreen.h"
#include "Enemy.h"
#include "Bullet.h"

const sf::Time Game::TimePerFrame = sf::seconds(1.f/60.f);
Game::Game() : _window(sf::VideoMode(_screenDimensions), "Software II Project",sf::Style::Fullscreen), _gameWindowProperties(), _player(),  _isMovingClockwise(false), _isMovingAntiClockwise(false)
{    
        srand(time(0));
		float halfSize = 0.5f;
		_window.setKeyRepeatEnabled(false);
        _window.setVerticalSyncEnabled(true);
		_gameWindowProperties = GameWindowProperties(_window.getSize().x, _window.getSize().y);
        _gameWindowProperties.displayProperties();
        _player = Player(_gameWindowProperties); 
		
		Enemy tempEnemy = Enemy(_gameWindowProperties);
        
		enemyStack.push_back(tempEnemy);
		
		_textureBackground.loadFromFile("Resources/Space.png");
        _texturePlayer.loadFromFile("Resources/spaceship.png");
		_textureEnemy.loadFromFile("Resources/Enemy.png");
        _textureBullet.loadFromFile("Resources/laser.png");
		
		_background.setTexture(_textureBackground);
		
        _playerShipSprite.setTexture(_texturePlayer);
		auto playerCenterX = _texturePlayer.getSize().x*halfSize;
		auto playerCenterY = _texturePlayer.getSize().y*halfSize;
		_playerShipSprite.setOrigin(playerCenterX, playerCenterY);
		_playerShipSprite.setScale(0.10f, 0.10f);
        std::cout << _playerShipSprite.getGlobalBounds().width << std::endl;
        std::cout << _playerShipSprite.getGlobalBounds().height << std::endl;
        
        _playerShipSprite.setPosition(_player.getPosition().getX(), _player.getPosition().getX());

		_enemyShipSprite.setTexture(_textureEnemy);
		auto enemyCenterX = _textureEnemy.getSize().x*halfSize;
		auto enemyCenterY = _textureEnemy.getSize().y*halfSize;
		_enemyShipSprite.setOrigin(enemyCenterX, enemyCenterY);
        _enemyShipSprite.setScale(0.10f, 0.10f);
        std::cout << _enemyShipSprite.getGlobalBounds().width << std::endl;
        std::cout << _enemyShipSprite.getGlobalBounds().height << std::endl;
        
        auto enemyWidth = _enemyShipSprite.getGlobalBounds().width;
        auto enemyHeight = _enemyShipSprite.getGlobalBounds().height;
        
        
                
        _enemyShipSprite.setPosition(_gameWindowProperties.getXOrigin(),_gameWindowProperties.getYOrigin());
		
		_bulletSprite.setTexture(_textureBullet);
		auto bulletCenterX = _textureBullet.getSize().x*halfSize;
		auto bulletCenterY = _textureBullet.getSize().y*halfSize;
		_bulletSprite.setOrigin(bulletCenterX, bulletCenterY);
		_bulletSprite.setScale(0.05f, 0.05f);
        std::cout << _bulletSprite.getGlobalBounds().width << std::endl;
        std::cout << _bulletSprite.getGlobalBounds().height << std::endl;
        
		_bulletSprite.setPosition(_player.getPosition().getX(), _player.getPosition().getY());
		
		enemySpriteControl.push_back(_enemyShipSprite);
}

void Game::run()
{
	SplashScreen splashscreen;
	splashscreen.show(_window);
	
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	while (_window.isOpen())
	{
		processInputEvents();
		processAI();
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;
			processInputEvents();
			update(TimePerFrame);
		}
		render();
	}
}

void Game::processAI()
{
	int indexEnemy = 0;
	for (auto& i : enemyStack)
	{   
		{
			if(i.isAlive() == false)
			{
				enemyStack.erase(enemyStack.begin());
				enemySpriteControl.erase(enemySpriteControl.begin());
			}
			else
			{
				i.move();
				enemySpriteControl[indexEnemy].setPosition(enemyStack[indexEnemy].getPosition().getX(), enemyStack[indexEnemy].getPosition().getY());
			}
			indexEnemy++;
		}
	}
	int indexBullets = 0;
    for (auto& i : _bullets)
    {   
        if(i.isBulletAlive())
        {
			i.updateBullet();
            bulletSprites[indexBullets].setPosition(i.getPosition().getX(), i.getPosition().getY());
            indexBullets++;
        }
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
        _window.draw(_background);
        _window.draw(_playerShipSprite); 
		
		for(auto& i : enemySpriteControl)
		{
			_window.draw(i);
		}
		
		int indexBulSprites = 0;
        for (auto bullet : _bullets)
        {
            if (bullet.isBulletAlive())
            {
                _window.draw(bulletSprites[indexBulSprites]);
                indexBulSprites++;
            }
        }

        _window.display();
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{	
	if (key == sf::Keyboard::Right)
		_isMovingClockwise = isPressed;
	else if (key == sf::Keyboard::Left)
		_isMovingAntiClockwise = isPressed;
	else if (key == sf::Keyboard::Space && isPressed == true)
    {
        Bullet bullet(_player.getPosition(), _gameWindowProperties);
        _bullets.push_back(bullet);
		_bulletSprite.setPosition(_player.getPosition().getX(), _player.getPosition().getY());
        bulletSprites.push_back(_bulletSprite);
    }
    else if (key == sf::Keyboard::BackSpace)
    {
        Enemy spawn = Enemy(_gameWindowProperties);
        enemyStack.push_back(spawn);
        _enemyShipSprite.setPosition(_gameWindowProperties.getXOrigin(),_gameWindowProperties.getYOrigin());
        enemySpriteControl.push_back(_enemyShipSprite);
    }
}
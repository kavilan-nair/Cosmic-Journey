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
#include "GameOverScreen.h"
#include "Enemy.h"
#include "EnemyBullet.h"
#include "Bullet.h"
#include "Satellites.h"

const sf::Time Game::TimePerFrame = sf::seconds(1.f/60.f);
Game::Game() : _window(sf::VideoMode(800,600 /*_screenDimensions*/), "Software II Project",sf::Style::Default /*sf::Style::Fullscreen*/), _gameWindowProperties(), _player(),  _isMovingClockwise(false), _isMovingAntiClockwise(false)
{    
        srand(time(0));
		_window.setKeyRepeatEnabled(false);
        _window.setVerticalSyncEnabled(true);
		_gameWindowProperties = GameWindowProperties(_window.getSize().x, _window.getSize().y);
        _player = Player(_gameWindowProperties); 
		
		_textureBackground.loadFromFile("Resources/space.png");
        _texturePlayer.loadFromFile("Resources/player.png");
		_textureEnemy.loadFromFile("Resources/enemy.png");
        _textureBullet.loadFromFile("Resources/laser.png");
        _textureEnemyBullet.loadFromFile("Resources/laser.png");
		_textureSatellite.loadFromFile("Resources/satellite.png");
		
		_background.setTexture(_textureBackground);

		setTextureOrigin(_texturePlayer,_playerShipSprite, 0.10f);
		setTextureOrigin(_textureEnemy,_enemyShipSprite, 0.10f);
		setTextureOrigin(_textureBullet,_bulletSprite, 0.05f);
		setTextureOrigin(_textureBullet,_enemyBulletSprite, 0.05f);
		setTextureOrigin(_textureSatellite,_satellite,0.125f);

		_playerShipSprite.setPosition(_player.getPosition().getX(), _player.getPosition().getX());
        _enemyShipSprite.setPosition(_gameWindowProperties.getXOrigin(),_gameWindowProperties.getYOrigin());
		_satellite.setPosition(_gameWindowProperties.getXOrigin(),_gameWindowProperties.getYOrigin());
}

void Game::setTextureOrigin(sf::Texture& spriteTexture, sf::Sprite& currSprite, float sizeScale)
{
	float halfScale = 0.5f; 
	spriteTexture.setSmooth(true);
	currSprite.setTexture(spriteTexture);
	auto oriXSprite = spriteTexture.getSize().x*halfScale;
	auto oriYSprite = spriteTexture.getSize().y*halfScale;
	currSprite.setOrigin(oriXSprite, oriYSprite);
	currSprite.setScale(sizeScale,sizeScale);
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
		spawnEnemyNormal();
		processAI();
        collisions();
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

void Game::spawnEnemyNormal()
{
	int spawnFactor = rand()%25+1;
	if(spawnFactor == 5)
	{
		Enemy spawn = Enemy(_gameWindowProperties);        
        enemyStack.push_back(spawn);
		std::cout << "Angle: " << spawn.getPosition().getAngle() << std::endl;
        _enemyShipSprite.setPosition(_gameWindowProperties.getXOrigin(),_gameWindowProperties.getYOrigin());
		//_enemyShipSprite.setRotation();
        enemySpriteControl.push_back(_enemyShipSprite);
	}

}

void Game::processAI()
{	
    if (_player.isDead())
    {
        GameOverScreen gameOverScreen;
        gameOverScreen.show(_window);
    }
    
	int indexEnemy = 0;
	for (auto& i : enemyStack)
	{   
		{
			if(i.isAlive() == false)
			{
				enemyStack.erase(enemyStack.begin() + indexEnemy);
				enemySpriteControl.erase(enemySpriteControl.begin() + indexEnemy);
            }
			else
			{
				i.move();
				enemySpriteControl[indexEnemy].setPosition(enemyStack[indexEnemy].getPosition().getX(), enemyStack[indexEnemy].getPosition().getY());
			}
			indexEnemy++;
		}
	}
	
	int indexSat = 0;
	for (auto& i : satStack)
	{   
		{
			if(i.isAlive() == false)
			{
				satStack.erase(satStack.begin() + indexSat);
				satSpriteControl.erase(satSpriteControl.begin() + indexSat);
			}
			else
			{
				i.move();
				satSpriteControl[indexSat].setPosition(satStack[indexSat].getPosition().getX(), satStack[indexSat].getPosition().getY());
			}
			indexSat++;
		}
	}
	
	int indexBullets = 0;
    for (auto& i : _bullets)
    {   
        if(i.isBulletAlive())
        {
			i.updateBullet();
            bulletSprites[indexBullets].setPosition(i.getPosition().getX(), i.getPosition().getY());
            
        }
        else
        {
            _bullets.erase(_bullets.begin() + indexBullets);
            bulletSprites.erase(bulletSprites.begin() + indexBullets);
        }
        
        indexBullets++;
    }
    
	int enemyFire = rand()%50 +1;
	if(enemyFire == 1)
	{
		bool fired = false;
		for(auto i : enemyStack)
		{

			if(i.isAlive() == true && fired == false)
			{
				EnemyBullet enemyBullet = EnemyBullet(i.getPosition(), _gameWindowProperties, getPlayer().getPosition());
				_enemyBullets.push_back(enemyBullet);
				_enemyBulletSprite.setPosition(i.getPosition().getX(), i.getPosition().getY());
				enemyBulletSprites.push_back(_enemyBulletSprite);
				fired = true;
			}
		}
	}
	
    int indexEnemyBullets = 0;
    for (auto& i : _enemyBullets)
    {
        if (i.isEnemyBulletAlive())
        {
            i.updateEnemyBullet();
            enemyBulletSprites[indexEnemyBullets].setPosition(i.getPosition().getX(), i.getPosition().getY());
            indexEnemyBullets++;
        }
        else
        {
            enemyBulletSprites.erase(enemyBulletSprites.begin() + indexEnemyBullets);
            _enemyBullets.erase(_enemyBullets.begin() + indexBullets);
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
                
            default:
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
		
		for(auto& i : satSpriteControl)
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
        
        int indexEnemyBulletSprites = 0;
        
        for(auto enemyBullet : _enemyBullets)
        {
            if (enemyBullet.isEnemyBulletAlive())
            {
                _window.draw(enemyBulletSprites[indexEnemyBulletSprites]);
                indexEnemyBulletSprites++;
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
    else if (key == sf::Keyboard::BackSpace && isPressed == true)
    {
        Enemy spawn = Enemy(_gameWindowProperties);        
        enemyStack.push_back(spawn);
        _enemyShipSprite.setPosition(_gameWindowProperties.getXOrigin(),_gameWindowProperties.getYOrigin());
		std::cout << "Angle sprite: " << spawn.getPosition().getAngle() << std::endl;
		
		_enemyShipSprite.setRotation(spawn.getPosition().getAngle()-90);
		std::cout << "Angle texture: " << _enemyShipSprite.getRotation() << std::endl;
        enemySpriteControl.push_back(_enemyShipSprite);
		_enemyShipSprite.setRotation(0);
		
		int randomStart = rand()%360;
		Satellites satSpawn1(_gameWindowProperties,randomStart,1);
		satStack.push_back(satSpawn1);
        _satellite.setPosition(_gameWindowProperties.getXOrigin(),_gameWindowProperties.getYOrigin());
        satSpriteControl.push_back(_satellite);
		
		Satellites satSpawn2(_gameWindowProperties,randomStart,2);
		satStack.push_back(satSpawn2);
        _satellite.setPosition(_gameWindowProperties.getXOrigin(),_gameWindowProperties.getYOrigin());
        satSpriteControl.push_back(_satellite);
		
		Satellites satSpawn3(_gameWindowProperties,randomStart,3);
		satStack.push_back(satSpawn3);
        _satellite.setPosition(_gameWindowProperties.getXOrigin(),_gameWindowProperties.getYOrigin());
        satSpriteControl.push_back(_satellite);
    }
}

void Game::collisions()
{
    int counter = 0;
    int counter2 = 0;
    int counter3 = 0;
    int counter4 = 0;
    int counter5 = 0;
    for (auto iter = bulletSprites.begin(); iter != bulletSprites.end(); iter++)
    {
        counter2 = 0;
        for (auto iter2 = enemySpriteControl.begin(); iter2 != enemySpriteControl.end(); iter2++)        
        {
            if (bulletSprites[counter].getGlobalBounds().intersects(enemySpriteControl[counter2].getGlobalBounds()))
            {
                std::cout << "ENEMY "<< counter2 << " collision" << std::endl;
                _bullets[counter].setBulletDead();
                enemyStack[counter2].setDead();
            }
            counter2++;
        }
        
        counter3 = 0;
        for (auto iter3 = satSpriteControl.begin(); iter3 != satSpriteControl.end(); iter3++)
        {
            if (bulletSprites[counter].getGlobalBounds().intersects(satSpriteControl[counter3].getGlobalBounds()))
            {
                std::cout << "SATELLITE "<< counter3 << " collision" << std::endl;
                _bullets[counter].setBulletDead();
                satStack[counter3].setDead();
            }
            counter3++;
        }
        
        counter++;
    }
    
    counter4 = 0;
    for (auto iter = enemyBulletSprites.begin(); iter != enemyBulletSprites.end(); iter++)
    {
        
        if (enemyBulletSprites[counter4].getGlobalBounds().intersects(_playerShipSprite.getGlobalBounds()))
        {
             
             _enemyBullets[counter4].setEnemyBulletDead();
             _player.decreaseLives();
             _player.respawn();
             std::cout << "Player has "<< _player.getLives()<< " lives" << std::endl;
            
        }
    
        counter4++;
    }
    
   
    counter5 = 0;
    for (auto iter = enemySpriteControl.begin(); iter != enemySpriteControl.end(); iter++)
    {
        if (enemySpriteControl[counter5].getGlobalBounds().intersects(_playerShipSprite.getGlobalBounds()))
        {
            enemyStack[counter5].setDead();
            _player.decreaseLives();
            _player.respawn();
             std::cout << "Player has "<< _player.getLives()<< " lives" << std::endl;
        }   
        counter5++;
    }
        
    
    
    
    
}
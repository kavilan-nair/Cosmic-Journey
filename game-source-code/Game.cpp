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
#include <string>

const sf::Time Game::TimePerFrame = sf::seconds(1.f/60.f);
Game::Game() : _window(sf::VideoMode(800, 600 /*_screenDimensions*/), "Software II Project",sf::Style::Default /*sf::Style::Fullscreen*/), _gameWindowProperties(), _player(),  _isMovingClockwise(false), _isMovingAntiClockwise(false)
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
        _textureEnemyBullet.loadFromFile("Resources/enemylaser.png");
		_textureSatellite.loadFromFile("Resources/satellite.png");
		
		_background.setTexture(_textureBackground);

		setTextureOrigin(_texturePlayer,_playerShipSprite, 0.10f);
		setTextureOrigin(_textureEnemy,_enemyShipSprite, 0.10f);
		setTextureOrigin(_textureBullet,_bulletSprite, 0.04f); //0.05f
		setTextureOrigin(_textureEnemyBullet,_enemyBulletSprite, 0.03f); //0.05f
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
		spawnEnemyElite();
		processAI();
        collisions();
        isGameOver();
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
	if(_enemiesSpawned != 50)
	{
		int spawnFactor = rand()%50+1;
		if(spawnFactor == 5)
		{
			Enemy spawn = Enemy(_gameWindowProperties);        
			enemyStack.push_back(spawn);
			_enemyShipSprite.setPosition(_gameWindowProperties.getXOrigin(),_gameWindowProperties.getYOrigin());
			_enemyShipSprite.setRotation(rand()%360);
			enemySpriteControl.push_back(_enemyShipSprite);
			_enemiesSpawned++;
		}
	}
}

void Game::spawnEnemyElite()
{
    if(_enemiesKilled == 20 || _enemiesKilled == 40)
	{
        if(satSpriteControl.size() == 0)
        {
            float randomStart = -(_player.getPosition().getAngle()*5)+90;
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
             _isSatGroupCreated = true;
        }
	}
	
}

void Game::processAI()
{	
    if (_player.isDead())
    {
        _lose = true;
    }
    
    if (enemyStack.size() == 0 && satStack.size() == 0 && _enemiesSpawned == 50) //&& satStack.size() == 0
    {
        _win = true;
    }
    
	int indexEnemy = 0;
	for (auto& i : enemyStack)
	{   
		{
			if(i.isAlive() == false)
			{				
				if(i.isRespawn() == true)
				{
					enemyStack.erase(enemyStack.begin() + indexEnemy);
					enemySpriteControl.erase(enemySpriteControl.begin() + indexEnemy);
                   
					
					Enemy spawn = Enemy(_gameWindowProperties);        
					enemyStack.push_back(spawn);
					_enemyShipSprite.setPosition(_gameWindowProperties.getXOrigin(),_gameWindowProperties.getYOrigin());
					_enemyShipSprite.setRotation(rand()%360);
					enemySpriteControl.push_back(_enemyShipSprite);
				}
				else
				{
					enemyStack.erase(enemyStack.begin() + indexEnemy);
					enemySpriteControl.erase(enemySpriteControl.begin() + indexEnemy);
                     _enemiesKilled++;
                    
				}
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
                 _enemiesKilled++;
			}
			else
			{
				i.move();
				satSpriteControl[indexSat].setPosition(satStack[indexSat].getPosition().getX(), satStack[indexSat].getPosition().getY());
			}
			indexSat++;
		}
	}
    
    if (satStack.size() == 0 && _isSatGroupCreated == true)
    {
        _numberOfSatGroupsDestroyed++;
        _isSatGroupCreated = false;
    }
    
    if (_numberOfSatGroupsDestroyed == 1)
    {
        _player.upgradeWeaponDouble();
    }
    
    if (_numberOfSatGroupsDestroyed == 2)
    {
        _player.upgradeWeaponTriple();
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
	
	int enemyFire = rand()%40 +1;         //rate of fire of enemies when within cone
	if(enemyFire == 1)
	{
		bool fired = false;
		for(auto i : enemyStack)
		{
			
			int enemyPos = (360 - (i.getPosition().getAngle()) + 90)%360;
			int playerPos = _player.getPosition().getAngle()*5;
			if(abs(playerPos) > 360){playerPos = playerPos%360;}
			if(playerPos < 0){playerPos = 360 + playerPos;}
			
			if((playerPos >= enemyPos - 15) && (playerPos <= (enemyPos + 15)%360 ))
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
	}
    
    int satFire = rand()%100 +1;  //rate of fire of satelliteswhen within cone
	if(satFire <= 9)
	{
		bool fired = false;
		for(auto i : satStack)
		{
			int enemyPos = (360 - (i.getPosition().getAngle()) + 90)%360;
			int playerPos = _player.getPosition().getAngle()*5;
			if(abs(playerPos) > 360){playerPos = playerPos%360;}
			if(playerPos < 0){playerPos = 360 + playerPos;}
			
			if((playerPos >= enemyPos - 15) && (playerPos <= (enemyPos + 15)%360 ))
			{
				if(i.isAlive() == true && fired == false)
				{
				EnemyBullet satEnemyBullet = EnemyBullet(i.getPosition(), _gameWindowProperties, getPlayer().getPosition());
                satEnemyBullet.setEnemyBulletAngle(i.getInitialAngle());
				_enemyBullets.push_back(satEnemyBullet);
				_enemyBulletSprite.setPosition(i.getPosition().getX(), i.getPosition().getY());
				enemyBulletSprites.push_back(_enemyBulletSprite);
				fired = true;
				}
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
        showLivesRemaining(_player.getLives(), _window);
		
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
         if (_player.getWeaponType() == WeaponType::Single)
        {
            Bullet bullet(_player.getPosition(), _gameWindowProperties, 1);
        _bullets.push_back(bullet);
		_bulletSprite.setPosition(_player.getPosition().getX(), _player.getPosition().getY());
        bulletSprites.push_back(_bulletSprite);
        }
        
        if (_player.getWeaponType() == WeaponType::Triple)
        {
            Bullet bullet1(_player.getPosition(), _gameWindowProperties, 1);
            _bullets.push_back(bullet1);
            _bulletSprite.setPosition(_player.getPosition().getX(), _player.getPosition().getY());
            bulletSprites.push_back(_bulletSprite);
            
            Bullet bullet2(_player.getPosition(), _gameWindowProperties, 2);
            _bullets.push_back(bullet2);
            _bulletSprite.setPosition(_player.getPosition().getX(), _player.getPosition().getY());
            bulletSprites.push_back(_bulletSprite);
            
             Bullet bullet3(_player.getPosition(), _gameWindowProperties, 3);
            _bullets.push_back(bullet3);
            _bulletSprite.setPosition(_player.getPosition().getX(), _player.getPosition().getY());
            bulletSprites.push_back(_bulletSprite);
            
        }
        
        if (_player.getWeaponType() == WeaponType::Double)
        {
            Bullet bullet4(_player.getPosition(), _gameWindowProperties, 2);
            _bullets.push_back(bullet4);
            _bulletSprite.setPosition(_player.getPosition().getX(), _player.getPosition().getY());
            bulletSprites.push_back(_bulletSprite);
            
             Bullet bullet5(_player.getPosition(), _gameWindowProperties, 3);
            _bullets.push_back(bullet5);
            _bulletSprite.setPosition(_player.getPosition().getX(), _player.getPosition().getY());
            bulletSprites.push_back(_bulletSprite);
        }
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
        }   
        counter5++;
    }
}

void Game::isGameOver()
{
    if (_lose)
    {
        GameOverScreen gameOverScreen;
        gameOverScreen.show(_window);
        _lose = true;
    }
    if (_win)
    {   
        WinnerScreen winnerScreen;
        winnerScreen.show(_window);
        _win =  true;
    }
}

void Game::showLivesRemaining(int lives, sf::RenderWindow& renderWindow)
{
    _font.loadFromFile("Resources/Agency_FB.ttf");
    std::string numberOfLives = std::to_string(lives-1) +" lives remaining"; 
    sf::Text sfLives(numberOfLives, _font);
    sfLives.setCharacterSize(24);
    sfLives.setPosition(20, 20);
    sfLives.setColor(sf::Color::Yellow);
    
    std::string numberOfenemiesKilled = std::to_string(56-_enemiesKilled) +" enemies remaining"; 
    sf::Text sfEnemiesKilled(numberOfenemiesKilled, _font);
    sfEnemiesKilled.setCharacterSize(24);
    sfEnemiesKilled.setPosition(600, 20);
    sfEnemiesKilled.setColor(sf::Color::Yellow);

    renderWindow.draw(sfLives);
    renderWindow.draw(sfEnemiesKilled);
}
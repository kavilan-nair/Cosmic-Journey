#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "EnemyBullet.h"
#include <vector>
#include "Satellites.h"

using namespace std;

class Game
{
	public: 
        Game();
        void run();
		Player& getPlayer(){return _player;};
		void setTextureOrigin(sf::Texture& spriteTexture, sf::Sprite& currSprite, float sizeScale);
    private:
        void processInputEvents();
		void processAI();
        void update();
        void render();
        void update(sf::Time deltaTime);	
        void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
        void collisions();

	public:
		sf::VideoMode _screenDimensions = sf::VideoMode::getDesktopMode();
		const float PI = atan(1)*4;
		
	private:
        static const sf::Time TimePerFrame;
		sf::RenderWindow _window;
		GameWindowProperties _gameWindowProperties;
		Player _player;
        bool _isMovingClockwise, _isMovingAntiClockwise;
        
		sf::Texture _textureBackground;
		sf::Texture _texturePlayer;
		sf::Texture _textureEnemy;
		sf::Texture _textureBullet;
        sf::Texture _textureEnemyBullet;
		sf::Texture _textureSatellite;
		
		sf::Sprite _background;
		sf::Sprite _playerShipSprite;
		sf::Sprite _enemyShipSprite;
		sf::Sprite _bulletSprite;
        sf::Sprite _enemyBulletSprite;
		sf::Sprite _satellite;
		
		std::vector<Enemy> enemyStack;
		std::vector<sf::Sprite> enemySpriteControl;
		
		std::vector<Satellites> satStack;
		std::vector<sf::Sprite> satSpriteControl;
        
        std::vector<EnemyBullet> _enemyBullets;
        std::vector<sf::Sprite> enemyBulletSprites;
        
        std::vector<Bullet> _bullets;
		std::vector<sf::Sprite> bulletSprites;
};

#endif
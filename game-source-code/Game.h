#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemy.h"

using namespace std;

class Game
{
    public: 
        Game();
        void run();
		Player& getPlayer(){return _player;};
		
    private:
        void processInputEvents();
		void processAI();
        void update();
        void render();
        
        void update(sf::Time deltaTime);	
        void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);

private:
        static const sf::Time	TimePerFrame;
        sf::RenderWindow _window;
		sf::Texture _texturePlayer;
		sf::Texture _textureEnemy;
        sf::Sprite _playerShipSprite;
		sf::Sprite _enemyShipSprite;
        Player _player;
		Enemy _enemy;
        bool _isMovingClockwise, _isMovingAntiClockwise;
       
};




#endif
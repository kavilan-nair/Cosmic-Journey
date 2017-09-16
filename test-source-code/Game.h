#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Player.h"

using namespace std;

class Game
{
    public: 
        Game();
        void run();
		Player& getPlayer(){return _player;};
		
    private:
        void processEvents();
        void update();
        void render();
        
        void update(sf::Time deltaTime);	
        void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);

private:
        static const sf::Time	TimePerFrame;
        sf::RenderWindow _window;
		sf::Texture _texture;
        sf::Sprite _playerShipSprite;
        Player _player;
        bool _isMovingClockwise, _isMovingAntiClockwise;
       
};




#endif
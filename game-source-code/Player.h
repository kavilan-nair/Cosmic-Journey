#ifndef PLAYER_H
#define PLAYER_H
#include "Position.h"
#include "GameWindowProperties.h"
#include <cmath>

class Player
{
	public:
        Player();
        Player(GameWindowProperties gameWindowProperties);
        void setPosition(Position position) { _position = position;};
        Position getPosition() { return _position;};
        
        void moveClockwise();
        void moveAntiClockwise();
        
		~Player();
        GameWindowProperties getWindowProperties(){return _gameWindowProperties;};
	
	public:
		float PI = atan(1)*4;  //same issue with making this const, breaks like a hoe
		float originFix = PI/2;

    private:
        Position _position;
        GameWindowProperties _gameWindowProperties;
       
};

#endif // PLAYER_H
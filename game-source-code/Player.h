#ifndef PLAYER_H
#define PLAYER_H
#include "Position.h"
#include "GameWindowProperties.h"

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
        
        
    private:
        Position _position;
        GameWindowProperties _gameWindowProperties;
    
};




#endif // PLAYER_H
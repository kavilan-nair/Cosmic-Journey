#ifndef POSITION_H
#define POSITION_H

class Position
{
    public:
        Position();
        int getX() const {return _x;};
		void setX(int x) {_x = x;};
		int getY() const {return _y;};
		void setY(int y) {_y = y;};
		float getAngle() const {return _angle;};
		void setAngle(float angle) { _angle = angle;};
		~Position();
        
    private:
        int _x, _y;
        int _angle;
    
};




#endif // POSITION_H
#ifndef POSITION_H
#define POSITION_H

class Position
{
	public:
		Position();
		
		int getX() const {return _x;};
		int getY() const {return _y;};
		int getAngle() const {return _angle;};
		int getRadius(){return _radius;};
		int getoriginX(){return _originX;};
		int getoriginY(){return _originY;};
		
		void setX(int x) {_x = x;};
		void setY(int y) {_y = y;};
		void setAngle(float angle){ _angle = angle;};
		void setRadius(int radius){_radius = radius;};
		void setoriginX(int originX){_originX = originX;};
		void setoriginY(int originY){_originY = originY;};
		
		~Position();
        
    private:
        int _x, _y;
		int _originX,_originY;
        int _angle;
		int _radius;
};

#endif // POSITION_H
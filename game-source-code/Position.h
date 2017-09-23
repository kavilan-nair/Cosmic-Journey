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
        int getHeight(){return _height;};
        int getWidth(){return _width;};
        
		void setX(int x) {_x = x;};
		void setY(int y) {_y = y;};
		void setAngle(float angle){ _angle = angle;};
		void setRadius(int radius){_radius = radius;};
		void setoriginX(int originX){_originX = originX;};
		void setoriginY(int originY){_originY = originY;};
        static void setHeight(int height){_height = height;};
        static void setWidth(int width){_width = width;};
		
        
		~Position();
        
    private:
        int _x, _y;
		int _originX,_originY;
        int _angle;
		int _radius;
        static int _height;
        static int _width;
};

#endif // POSITION_H
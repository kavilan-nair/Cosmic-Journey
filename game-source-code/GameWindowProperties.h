#ifndef GAMEWINDOWPROPERTIES_H
#define GAMEWINDOWPROPERTIES_H

class GameWindowProperties
{
	public:
		GameWindowProperties();
		GameWindowProperties(int width, int height);
		void setWidth(int width) {_width = width;};
		int getWidth() {return _width;};
		void setHeight(int height) {_height = height;};
		int getHeight() {return _height;};
		void setXOrigin(int xOrigin) {_xOrigin = xOrigin;};
		int getXOrigin() {return _xOrigin;};
		void setYOrigin(int yOrigin) { _yOrigin = yOrigin;};
        int getYOrigin() {return _yOrigin;};
        void setRadius(int radius) { _radius = radius;};
        int getRadius() {return _radius;};
		~GameWindowProperties();	
	
	private:
		int _width, _height;
		int _xOrigin, _yOrigin, _radius;
};







#endif //GAMEWINDOWPROPERTIES_H

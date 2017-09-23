#ifndef GAMEWINDOWPROPERTIES_H
#define GAMEWINDOWPROPERTIES_H

class GameWindowProperties
{
	public:
		GameWindowProperties();
		GameWindowProperties(int width, int height);
		~GameWindowProperties();	
        
        void displayProperties();
		
		void setWidth(int width) {_width = width;};
		void setHeight(int height) {_height = height;};
		void setXOrigin(int xOrigin) {_xOrigin = xOrigin;};
		void setYOrigin(int yOrigin) { _yOrigin = yOrigin;};
        void setRadius(int radius) { _radius = radius;};
		
		int getWidth() {return _width;};
		int getHeight() {return _height;};
		int getXOrigin() {return _xOrigin;};
        int getYOrigin() {return _yOrigin;};
        int getRadius() {return _radius;};
	
	private:
		int _width, _height;
		int _xOrigin, _yOrigin, _radius;
};

#endif //GAMEWINDOWPROPERTIES_H
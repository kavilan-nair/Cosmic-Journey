#ifndef GRID_H
#define GRID_H

/**
* Grid class - abstracted representation of the game playing screen.
*/
class Grid
{
	public:
		/**
		* @brief Parameterized constructor. Creates a Grid object with the radius and center of a circle based on the input parameters.
		* @param width is an int which defines the width value of the screen.
		* @param height is an int which defines the height value of the screen.
		*/
		Grid(const int& width, const int& height);
		/**
		* @brief Default deconstructor. Destroys the Grid once it has gone out of scope.
		*/
		~Grid();
		/**
		* @brief Gets a constant copy of the width of the Grid.
		* @return int with width value.
		*/
		int getWidth()   const;
		/**
		* @brief Gets a constant copy of the height of the Grid.
		* @return int with height value.
		*/
		int getHeight()  const;
		/**
		* @brief Gets a constant copy of the x position center of the Grid.
		* @return int with x value at center.
		*/
		int getCenterX() const;
		/**
		* @brief Gets a constant copy of the y position center of the Grid.
		* @return int with y value at center.
		*/
		int getCenterY() const;
		/**
		* @brief Gets a constant copy of the radius of the abstracted circle of the Grid.
		* @return int with value of radius.
		*/
		int getRadius()  const;
		
	private:
		int _width, _height;
		int _centerX, _centerY;
		int _radius;
};

#endif // GRID_H

#ifndef POSITION_H
#define POSITION_H

/**
* Position class - data class encapsulating the getters, setters and variables that define the position of an objects.
*/
class Position
{
    public:
        /**
        * @brief Default constructor. Creates a Position object containing the radius, angle, center x and y coordinates of a circle, current x and y coordinates.
        */
        Position();
        /**
        * @brief Default destructor. Destroys the Position object.
        */
        ~Position();
        /**
        * @brief Gets a constant copy of the current x coordinate of the object.
        * @return int with x coordinate value.
        */
        int getXpos() const;
        /**
        * @brief Gets a constant copy of the current y coordinate of the object.
        * @return int with y coordinate value.
        */
        int getYpos() const;
        /**
        * @brief Gets a constant copy of the radius of the object of the circle of the Grid.
        * @return int with radius value.
        */
        int getRadius() const;
        /**
        * @brief Gets a constant copy of the angle of the object.
        * @return int with angle value.
        */
        int getAngle() const;
        /**
        * @brief Gets a constant copy of the original x coordinate of the object.
        * @return int with x coordinate value.
        */
        int getXposInitial() const;
        /**
        * @brief Gets a constant copy of the original y coordinate of the object.
        * @return int with y coordinate value.
        */
        int getYposInitial() const;
        /**
        * @brief Sets a value as the x coordinate of the object.
        * @param xPos is an int which defines x coordinate of an object.
        */
        void setXpos(int xPos);
        /**
        * @brief Sets a value as the y coordinate of the object.
        * @param yPos is an int which defines y coordinate of an object.
        */
        void setYpos(int yPos);
        /**
        * @brief Sets a value as the radius of the object.
        * @param radius is an int which defines the radius of the grid.
        */
        void setRadius(int radius);
        /**
        * @brief Sets a value as the angle of the object.
        * @param angle is an int which defines the angle of the object against the grid.
        */
        void setAngle(int angle);
        /**
        * @brief Sets a value as the initial x coordinate of the object.
        * @param xPosInitial is an int which defines x coordinate of an object.
        */
        void setXposInitial(int xPosInitial);
        /**
        * @brief Sets a value as the initial y coordinate of the object.
        * @param yPosInitial is an int which defines y coordinate of an object.
        */
        void setYposInitial(int yPosInitial);
            
    private:
        int _xPosInitial, _yPosInitial;
        int _xPos, _yPos;
        int _radius, _angle;
};

#endif // POSITION_H
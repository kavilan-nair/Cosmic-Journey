#ifndef GRID_H
#define GRID_H

class Grid
{
public:
    Grid(const int& width, const int& height);
    ~Grid();
    int getWidth()   const;
    int getHeight()  const;
    int getCenterX() const;
    int getCenterY() const;
    int getRadius()  const;
    
private:
    int _width, _height;
    int _centerX, _centerY;
    int _radius;
};

#endif // GRID_H

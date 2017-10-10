#ifndef POSITION_H
#define POSITION_H

class Position
{
public:
    Position();
    ~Position();
    int getXpos() const;
    int getYpos() const;
    int getRadius() const;
    int getAngle() const;
    int getXposInitial() const;
    int getYposInitial() const;
    void setXpos(int xPos);
    void setYpos(int yPos);
    void setRadius(int radius);
    void setAngle(int angle);
    void setXposInitial(int xPosInitial);
    void setYposInitial(int yPosInitial);
        
private:
    int _xPosInitial, _yPosInitial;
    int _xPos, _yPos;
    int _radius, _angle;
};

#endif // POSITION_H
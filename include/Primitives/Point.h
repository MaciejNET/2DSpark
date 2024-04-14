#ifndef INC_2DSPARK_POINT_H
#define INC_2DSPARK_POINT_H

class Point
{
public:
    Point(float x, float y) : _x(x), _y(y) {}
    float GetX() const;
    float GetY() const;
    void SetX(float x);
    void SetY(float y);
private:
    float _x;
    float _y;
};


#endif //INC_2DSPARK_POINT_H

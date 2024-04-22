#ifndef INC_2DSPARK_POINT_H
#define INC_2DSPARK_POINT_H

#include <utility>

class Point
{
public:
    Point(float x, float y);
    float GetX() const;
    float GetY() const;
    float GetXPixels() const;
    float GetYPixels() const;
    std::pair<float, float> GetXY() const;
    std::pair<float, float> GetXYPixels() const;
    void SetX(float x);
    void SetY(float y);
    void SetXY(float x, float y);
private:
    float _x;
    float _y;
};


#endif //INC_2DSPARK_POINT_H

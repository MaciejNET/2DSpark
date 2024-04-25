#ifndef INC_2DSPARK_POINT_H
#define INC_2DSPARK_POINT_H

#include <utility>

/**
 * Klasa reprezentująca punkt
 */
class Point
{
public:
    /**
     * Konstruktor klasy
     * @param x - współrzędna x
     * @param y - współrzędna y
     */
    Point(float x, float y);

    /**
     * Metoda zwracająca współrzędną x
     * @return współrzędna x
     */
    float GetX() const;

    /**
     * Metoda zwracająca współrzędną y
     * @return współrzędna y
     */
    float GetY() const;

    /**
     * Metoda zwracająca współrzędne x w pikselach
     * @return wspórzędna x w pikselach
     */
    float GetXPixels() const;

    /**
     * Metoda zwracająca współrzędne y w pikselach
     * @return wspórzędna y w pikselach
     */
    float GetYPixels() const;

    /**
     * Metoda zwracająca współrzędne x i y
     * @return współrzędne x i y
     */
    std::pair<float, float> GetXY() const;

    /**
     * Metoda zwracająca współrzędne x i y w pikselach
     * @return współrzędne x i y w pikselach
     */
    std::pair<float, float> GetXYPixels() const;

    /**
     * Metoda ustawiająca współrzędną x
     * @param x - współrzędna x
     */
    void SetX(float x);

    /**
     * Metoda ustawiająca współrzędną y
     * @param y - współrzędna y
     */
    void SetY(float y);

    /**
     * Metoda ustawiająca współrzędne x i y
     * @param x - współrzędna x
     * @param y - współrzędna y
     */
    void SetXY(float x, float y);
private:
    float _x;
    float _y;
};


#endif //INC_2DSPARK_POINT_H

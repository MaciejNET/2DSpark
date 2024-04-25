#ifndef INC_2DSPARK_GAMEOBJECT_H
#define INC_2DSPARK_GAMEOBJECT_H

/**
 * Bazowy obiekt gry
 */
class GameObject
{
public:
    /**
     * Konstruktor służący do tworzenia obiektu
     */
    GameObject() = default;

    /**
     * Destruktor
     */
    virtual ~GameObject() = default;

    /**
     * Metoda służąca do rysowania obiektu
     */
    virtual void Draw() const = 0;

    /**
     * Metoda służąca do aktualizowania obiektu podczas renderowania
     * @param deltaTime
     */
    virtual void Update(float deltaTime) = 0;

    /**
     * Metoda służąca do przesuwania obiektu
     * @param x
     * @param y
     */
    virtual void Translate(float x, float y) = 0;

    /**
     * Metoda służąca do obracania obiektu
     * @param angle
     */
    virtual void Rotate(float angle) = 0;

    /**
     * Metoda służąca do skalowania obiektu
     * @param x
     * @param y
     */
    virtual void Scale(float x, float y) = 0;
};

#endif //INC_2DSPARK_GAMEOBJECT_H

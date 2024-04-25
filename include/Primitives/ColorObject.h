#ifndef INC_2DSPARK_COLOROBJECT_H
#define INC_2DSPARK_COLOROBJECT_H
#include "GameObject.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <string>
#include <fstream>
#include <sstream>

/**
 * Klasa bazowa dla obiektów które mają kolor
 */
class ColorObject : public GameObject
{
public:
    /**
     * Konstruktor klasy
     * @param r - czerwony kolor
     * @param g - zielony kolor
     * @param b - niebieski kolor
     * @param filled - czy obiekt ma być wypełniony
     * @param thickness - grubość linii
     */
    ColorObject(float r, float g, float b, bool filled, float thickness);
    ColorObject();
    virtual ~ColorObject() = default;

    /**
     * Ustawia kolor obiektu
     * @param r - czerwony kolor
     * @param g - zielony kolor
     * @param b - niebieski kolor
     */
    void SetColor(float r, float g, float b);

    /**
     * Ustawia czy obiekt ma być wypełniony
     * @param filled - czy obiekt ma być wypełniony
     */
    void SetFilled(bool filled);

    /**
     * Ustawia grubość linii
     * @param thickness - grubość linii
     */
    void SetThickness(float thickness);

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

    GLuint GetShaderProgram() const;
    GLuint GetVertexShader() const;
    GLuint GetFragmentShader() const;
    std::string GetVertexShaderSource() const;
    std::string GetFragmentShaderSource() const;

    /**
     * Metoda zwracająca czerwony kolor
     * @return czerwony kolor
     */
    float GetR() const;

    /**
     * Metoda zwracająca zielony kolor
     * @return zielony kolor
     */
    float GetG() const;

    /**
     * Metoda zwracająca niebieski kolor
     * @return niebieski kolor
     */
    float GetB() const;
private:
    float _r;
    float _g;
    float _b;
protected:
    bool _filled;
    float _thickness;


    GLuint _shaderProgram;
    GLuint _vertexShader;
    GLuint _fragmentShader;

    std::string ReadFile(const std::string& filePath);

    std::string _vertexShaderSource = R"(
        #version 330 core
        layout(location = 0) in vec3 aPos;
        void main()
        {
            gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
        }
    )";

    std::string _fragmentShaderSource =
        "#version 330 core\n"
        "out vec4 FragColor;\n"
        "void main()\n"
        "{\n"
        "    FragColor = vec4(" + std::to_string(_r) + ", " + std::to_string(_g) + ", " + std::to_string(_b) + ", 1.0);\n"
        "}\n";

    void CompileShaders();
};
#endif // INC_2DSPARK_COLOROBJECT_H

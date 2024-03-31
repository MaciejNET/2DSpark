#ifndef INC_2DSPARK_COLOROBJECT_H
#define INC_2DSPARK_COLOROBJECT_H
#include "GameObject.h"
#include <GLFW/glfw3.h>
#include <glad/glad.h>

class ColorObject : public GameObject
{
public:
	ColorObject(float r, float g, float b);
	ColorObject();
	virtual ~ColorObject() = default;
	void SetColor(float r, float g, float b);
	virtual void Draw() const = 0;

    GLuint GetShaderProgram() const
    {
        return _shaderProgram;
    }
    GLuint GetVertexShader() const
    {
        return _vertexShader;
    }
    GLuint GetFragmentShader() const
    {
        return _fragmentShader;
    }
private:
	float _r;
	float _g;
	float _b;


    GLuint _shaderProgram;
    GLuint _vertexShader;
    GLuint _fragmentShader;

    std::string _vertexShaderSource = R"(
        #version 330 core
        layout(location = 0) in vec3 aPos;
        void main()
        {
            gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
        }
    )";

    std::string _fragmentShaderSource = R"(
        #version 330 core
        out vec4 FragColor;
        uniform float r;
        uniform float g;
        uniform float b;
        void main()
        {
            FragColor = vec4(r, g, b, 1.0);
        }
    )";

    void CompileShaders();
};
#endif // INC_2DSPARK_COLOROBJECT_H

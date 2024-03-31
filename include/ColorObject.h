#ifndef INC_2DSPARK_COLOROBJECT_H
#define INC_2DSPARK_COLOROBJECT_H
#include "GameObject.h"
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <string>

class ColorObject : public GameObject
{
public:
	ColorObject(float r, float g, float b);
	ColorObject();
	virtual ~ColorObject() = default;
	void SetColor(float r, float g, float b);
	virtual void Draw() const = 0;

    GLuint GetShaderProgram() const;
    GLuint GetVertexShader() const;
    GLuint GetFragmentShader() const;
    std::string GetVertexShaderSource() const;
    std::string GetFragmentShaderSource() const;
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

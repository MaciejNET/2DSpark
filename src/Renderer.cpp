#include "../include/Renderer.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

Renderer::Renderer() 
{
#ifdef __unix__
    const char* vertex_shader_path = "../shaders/vertex_shader.glsl";
    const char* fragment_shader_path = "../shaders/fragment_shader.glsl";
#elif __aarch64__
    const char* vertex_shader_path = "../shaders/vertex_shader.glsl";
    const char* fragment_shader_path = "../shaders/fragment_shader.glsl";
#elif defined(_WIN32) || defined(_WIN64)
    const char* vertex_shader_path = "../../../shaders/vertex_shader.glsl";
    const char* fragment_shader_path = "../../../shaders/fragment_shader.glsl";
#endif

    programID = LoadShaders(vertex_shader_path, fragment_shader_path);
}

Renderer::~Renderer() 
{
    glDeleteProgram(programID);
}

void Renderer::Render() const 
{
    glUseProgram(programID);
    for (const auto& object : _objects)
        object->Draw();
    glUseProgram(0);
}

GLuint Renderer::LoadShaders(const char* vertex_file_path, const char* fragment_file_path) 
{
    GLuint VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
    GLuint FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

    std::string VertexShaderCode;
    std::ifstream VertexShaderStream(vertex_file_path, std::ios::in);

    if (VertexShaderStream.is_open()) 
    {
        std::stringstream sstr;
        sstr << VertexShaderStream.rdbuf();
        VertexShaderCode = sstr.str();
        VertexShaderStream.close();
    }
    else 
    {
        std::cerr << "Cannot open " << vertex_file_path << ". Are you in the right directory?" << std::endl;
        getchar();
        return 0;
    }

    char const* VertexSourcePointer = VertexShaderCode.c_str();
    glShaderSource(VertexShaderID, 1, &VertexSourcePointer, NULL);
    glCompileShader(VertexShaderID);

    std::string FragmentShaderCode;
    std::ifstream FragmentShaderStream(fragment_file_path, std::ios::in);
    if (FragmentShaderStream.is_open()) 
    {
        std::stringstream sstr;
        sstr << FragmentShaderStream.rdbuf();
        FragmentShaderCode = sstr.str();
        FragmentShaderStream.close();
    }

    char const* FragmentSourcePointer = FragmentShaderCode.c_str();
    glShaderSource(FragmentShaderID, 1, &FragmentSourcePointer, NULL);
    glCompileShader(FragmentShaderID);

    GLuint ProgramID = glCreateProgram();
    glAttachShader(ProgramID, VertexShaderID);
    glAttachShader(ProgramID, FragmentShaderID);
    glLinkProgram(ProgramID);

    glDeleteShader(VertexShaderID);
    glDeleteShader(FragmentShaderID);

    return ProgramID;
}

void Renderer::AddObject(const GameObject* object) 
{
    _objects.push_back(object);
}

void Renderer::RemoveObject(const GameObject* object) 
{
    _objects.erase(std::remove(_objects.begin(), _objects.end(), object), _objects.end());
}

void Renderer::ClearObjects() 
{
    _objects.clear();
}

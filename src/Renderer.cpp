#include "../include/Renderer.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

Renderer::Renderer() {
    // Load and compile shaders
    programID = LoadShaders("../../../shaders/vertex_shader.glsl", "../../../shaders/fragment_shader.glsl");

}

Renderer::~Renderer() {
    glDeleteProgram(programID);
}

void Renderer::Render() const {
    glUseProgram(programID);  // Use the shader program
    for (const auto& object : _objects)
        object->Draw();
    glUseProgram(0);  // Unbind the shader program
}

GLuint Renderer::LoadShaders(const char* vertex_file_path, const char* fragment_file_path) {
    // Create the shaders
    GLuint VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
    GLuint FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

    // Read the Vertex Shader code from the file
    std::string VertexShaderCode;
    std::ifstream VertexShaderStream(vertex_file_path, std::ios::in);
    if (VertexShaderStream.is_open()) {
        std::stringstream sstr;
        sstr << VertexShaderStream.rdbuf();
        VertexShaderCode = sstr.str();
        VertexShaderStream.close();
    }
    else {
        std::cerr << "Cannot open " << vertex_file_path << ". Are you in the right directory?" << std::endl;
        getchar();
        return 0;
    }

    // Compile Vertex Shader
    char const* VertexSourcePointer = VertexShaderCode.c_str();
    glShaderSource(VertexShaderID, 1, &VertexSourcePointer, NULL);
    glCompileShader(VertexShaderID);

    // Compile Fragment Shader
    std::string FragmentShaderCode;
    std::ifstream FragmentShaderStream(fragment_file_path, std::ios::in);
    if (FragmentShaderStream.is_open()) {
        std::stringstream sstr;
        sstr << FragmentShaderStream.rdbuf();
        FragmentShaderCode = sstr.str();
        FragmentShaderStream.close();
    }

    char const* FragmentSourcePointer = FragmentShaderCode.c_str();
    glShaderSource(FragmentShaderID, 1, &FragmentSourcePointer, NULL);
    glCompileShader(FragmentShaderID);

    // Link the program
    GLuint ProgramID = glCreateProgram();
    glAttachShader(ProgramID, VertexShaderID);
    glAttachShader(ProgramID, FragmentShaderID);
    glLinkProgram(ProgramID);

    glDeleteShader(VertexShaderID);
    glDeleteShader(FragmentShaderID);

    return ProgramID;
}

void Renderer::AddObject(const GameObject* object) {
    _objects.push_back(object);
}

void Renderer::RemoveObject(const GameObject* object) {
    _objects.erase(std::remove(_objects.begin(), _objects.end(), object), _objects.end());
}

void Renderer::ClearObjects() {
    _objects.clear();
}

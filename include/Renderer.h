#ifndef INC_2DSPARK_RENDERER_H
#define INC_2DSPARK_RENDERER_H

#include <vector>
#include <string>
#include <glad/glad.h>
#include "GameObject.h"

class Renderer 
{
public:
    Renderer();
    ~Renderer();
    void AddObject(const GameObject* object);
    void RemoveObject(const GameObject* object);
    void Render() const;
    void ClearObjects();
    GLuint LoadShaders(const char* vertex_file_path, const char* fragment_file_path);

private:
    std::vector<const GameObject*> _objects;
    GLuint programID;
};

#endif

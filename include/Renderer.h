#ifndef INC_2DSPARK_RENDERER_H
#define INC_2DSPARK_RENDERER_H

#include <vector>
#include <string>
#include <glad/glad.h>
#include "Primitives/GameObject.h"

class Renderer 
{
public:
    Renderer();
    ~Renderer();
    void AddObject(GameObject* object);
    void RemoveObject(GameObject* object);
    void Render(float deltaTime);
    void ClearObjects();
    GLuint LoadShaders(const char* vertex_file_path, const char* fragment_file_path);

private:
    std::vector<GameObject*> _objects;
    GLuint programID;
};

#endif

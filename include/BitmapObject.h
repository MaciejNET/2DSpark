#pragma once
#include <string>
#include "GameObject.h"
#include "../include/stb_image.h"

class BitmapObject : public GameObject 
{
public:
    BitmapObject(const std::string& imagePath);
    ~BitmapObject();

    void Draw() const override;

private:
    unsigned int textureId;
    unsigned int VBO, VAO, EBO;
    void loadTexture(const std::string& imagePath);
    void setupMesh();
};

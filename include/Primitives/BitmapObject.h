#pragma once
#include <string>
#include "GameObject.h"
#include "stb_image.h"

/**
 * Klasa reprezentująca obiekt bitmapowy
 */
class BitmapObject : public GameObject 
{
public:
    BitmapObject(const std::string& imagePath);
    ~BitmapObject();

    void Draw() const override;
    void Update(float deltaTime) override {};
    void Translate(float x, float y) override;
    void Rotate(float angle) override;
    void Scale(float x, float y) override;

private:
    unsigned int textureId;
    unsigned int VBO, VAO, EBO;
    void loadTexture(const std::string& imagePath);
    void setupMesh();
};

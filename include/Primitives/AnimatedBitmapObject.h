#ifndef INC_2DSPARK_ANIMATEDOBJECTS_H
#define INC_2DSPARK_ANIMATEDOBJECTS_H

#include <string>
#include <vector>
#include "GameObject.h"
#include "stb_image.h"
#include "glad/glad.h"
#include <iostream>

/**
 * Klasa reprezentująca animowany obiekt
 */
class AnimatedBitmapObject : public GameObject
{
public:
    AnimatedBitmapObject(const std::vector<std::string>& framePaths, float frameDuration);
    ~AnimatedBitmapObject();
    void Draw() const override;
    void Update(float deltaTime) override;
    void Translate(float x, float y) override;
    void Rotate(float angle) override;
    void Scale(float x, float y) override;

private:
    std::vector<unsigned int> textureIds;
    unsigned int VBO, VAO, EBO;
    unsigned int currentFrameIndex;
    float frameDuration;
    float elapsedTime;

    void loadTexture(const std::string& imagePath);
    void setupMesh();
    void switchToNextFrame();
};

#endif //INC_2DSPARK_ANIMATEDOBJECTS_H
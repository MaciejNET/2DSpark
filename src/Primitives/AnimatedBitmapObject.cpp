#include "../../include/Primitives/AnimatedBitmapObject.h"
#include "glad/glad.h"
#include <iostream>

AnimatedBitmapObject::AnimatedBitmapObject(const std::vector<std::string>& framePaths, float frameDuration)
        : frameDuration(frameDuration), elapsedTime(0.0f), currentFrameIndex(0)
{
    for (const auto& framePath : framePaths)
    {
        loadTexture(framePath);
    }
    setupMesh();
}

AnimatedBitmapObject::~AnimatedBitmapObject()
{
    for (auto textureId : textureIds)
    {
        glDeleteTextures(1, &textureId);
    }
    glDeleteBuffers(1, &VBO);
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &EBO);
}

void AnimatedBitmapObject::loadTexture(const std::string& imagePath)
{
    unsigned int textureId;
    glGenTextures(1, &textureId);
    glBindTexture(GL_TEXTURE_2D, textureId);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    int width, height, nrChannels;
    unsigned char* data = stbi_load(imagePath.c_str(), &width, &height, &nrChannels, 0);
    if (data)
    {
        GLenum format = (nrChannels == 4) ? GL_RGBA : GL_RGB;
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
        textureIds.push_back(textureId);
    }
    else
    {
        std::cout << "Failed to load texture: " << imagePath << std::endl;
    }
    stbi_image_free(data);
}


void AnimatedBitmapObject::setupMesh()
{
    float vertices[] = {

        0.5f,  0.5f, 0.0f, 1.0f, 1.0f,
        0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
       -0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
       -0.5f,  0.5f, 0.0f, 0.0f, 1.0f
    };
    unsigned int indices[] =
    {
        0, 1, 3,
        1, 2, 3
    };

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void AnimatedBitmapObject::Draw() const
{
    glBindTexture(GL_TEXTURE_2D, textureIds[currentFrameIndex]);

    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}

void AnimatedBitmapObject::Update(float deltaTime)
{
    elapsedTime += deltaTime;

    if (elapsedTime >= frameDuration)
    {
        switchToNextFrame();
        elapsedTime = 0.0f;
    }
}

void AnimatedBitmapObject::switchToNextFrame()
{
    currentFrameIndex = (currentFrameIndex + 1) % textureIds.size();
}

void AnimatedBitmapObject::Translate(float x, float y)
{
    // Not implemented
}

void AnimatedBitmapObject::Rotate(float angle)
{
    // Not implemented
}

void AnimatedBitmapObject::Scale(float x, float y)
{
    // Not implemented
}

#ifndef INC_2DSPARK_RENDERER_H
#define INC_2DSPARK_RENDERER_H

#include <vector>
#include <string>
#include <glad/glad.h>
#include "Primitives/GameObject.h"

/**
 * Klasa służąca do renderowania obiektów
 */
class Renderer 
{
public:
    /**
     * Kontruktor klasy
     */
    Renderer();

    /**
     * Destruktor klasy
     */
    ~Renderer();

    /**
     * Metoda służąca do dodawania obiektu który ma być renderowany
     * @param object obiekt który ma być renderowany
     */
    void AddObject(GameObject* object);

    /**
     * Metoda służąda do usuwania renderowanego obiektu
     * @param object obiekt który ma przesztać być renderowany
     */
    void RemoveObject(GameObject* object);

    /**
     * Metoda służąca do renderowania obiektów
     * @param deltaTime
     */
    void Render(float deltaTime);

    /**
     * Metoda służaca do usuwania wszystkich renderowanych obiektów
     */
    void ClearObjects();

    /**
     * Metoda do ładowania shaderów
     * @param vertex_file_path ściężka do vertex shadera
     * @param fragment_file_path ścieżka do fragment shadera
     * @return
     */
    GLuint LoadShaders(const char* vertex_file_path, const char* fragment_file_path);

private:
    std::vector<GameObject*> _objects;
    GLuint programID;
};

#endif

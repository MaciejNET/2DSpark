#ifndef INC_2DSPARK_COLOROBJECT_H
#define INC_2DSPARK_COLOROBJECT_H
#include "GameObject.h"
#include <GLFW/glfw3.h>
#include <glad/glad.h>

class ColorObject : public GameObject
{
public:
	ColorObject(float r, float g, float b) : _r(r), _g(g), _b(b) {}
	virtual ~ColorObject() = default;
	void SetColor(float r, float g, float b);
	virtual void Draw() const = 0;
private:
	float _r;
	float _g;
	float _b;
};

#endif // INC_2DSPARK_COLOROBJECT_H

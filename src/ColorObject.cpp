#include "../include/ColorObject.h"
#include <iostream>

ColorObject::ColorObject(float r, float g, float b) : _r(r), _g(g), _b(b) {}

void ColorObject::SetColor(float r, float g, float b)
{
	_r = r;
	_g = g;
	_b = b;
}
void ColorObject::Draw() const
{
	//Z mojej nik³ej wiedzy wynika, ¿e tu bêdzie umieszczona logika
	//do rysowania obiektów wed³ug kolorów rgb :D
}
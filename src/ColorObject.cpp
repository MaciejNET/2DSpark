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
	//Z mojej nik�ej wiedzy wynika, �e tu b�dzie umieszczona logika
	//do rysowania obiekt�w wed�ug kolor�w rgb :D
}
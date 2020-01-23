#pragma once

#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"


#include "GLUTCallback.h"

#define REFRESH_RATE 16

class OpenGL
{
public:
	OpenGL(int argc, char* argv[]);

	void Display();
	void DrawPolygon(float points[4][2]);
	void DrawPolygon(float points[4][2], float r, float g, float b, float a);
	void DrawTriangle(float points[3][2]);
	void Update();

	float squareA[4][2] = {
		{0,0},
		{0.25, 0},
		{0.25, -0.25},
		{0,-0.25}
	};

	double backgroundColor[4];

	void Keyboard(unsigned char key, int x, int y);

private:
	float rotation = 0.0f;
};


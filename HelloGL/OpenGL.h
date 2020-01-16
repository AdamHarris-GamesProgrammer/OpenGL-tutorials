#pragma once

#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"


#include "GLUTCallback.h"

class OpenGL
{
public:
	OpenGL(int argc, char* argv[]);

	void Display();
	void DrawPolygon(float points[4][2]);
	void DrawPolygon(float points[4][2], float r, float g, float b, float a);
	void DrawTriangle(float points[3][2]);


	float triangleA[3][2] = {
		{-0.9, -0.9},
		{-1, -0.7},
		{-0.8, -0.7}
	};

	float triangleB[3][2] = {
		{-0.2, -0.9},
		{-0.4, -0.7},
		{-0.7, -0.6}
	};

	float squareA[4][2] = {
		{0,0},
		{0.25, 0},
		{0.25, -0.25},
		{0,-0.25}
	};


	double squaresArray[6][4][2];
	double backgroundColor[4];
};


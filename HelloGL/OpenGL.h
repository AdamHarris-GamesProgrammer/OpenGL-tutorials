#pragma once

#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"


#include "GLUTCallback.h"

#define REFRESH_RATE 16

struct Vector3 {
	float x, y, z;

	Vector3(float xValue = 0.0f, float yValue = 0.0f, float  zValue = 0.0f) {
		x = xValue;
		y = yValue;
		z = zValue;
	}
};

struct Camera {
	Vector3 eye;
	Vector3 center;
	Vector3 up;
};

struct Color {
	GLfloat r, g, b;
};

struct Vertex {
	GLfloat x, y, z;
};

class OpenGL
{
public:
	OpenGL(int argc, char* argv[]);
	~OpenGL();

	void Display();
	void DrawPolygon(float points[4][2]);
	void DrawPolygon(float points[4][2], float r, float g, float b, float a);
	void DrawTriangle(float points[3][2]);

	void DrawCube();

	void Update();

	float squareA[4][2] = {
		{0,0},
		{0.25, 0},
		{0.25, -0.25},
		{0,-0.25}
	};

	void Keyboard(unsigned char key, int x, int y);

private:
	float rotationY = 0.0f;
	float rotationX = 0.0f;

	Camera* mCamera;

	static Vertex verticies[];
	static Color colors[];

	static Vertex indexedVerticies[];
	static Color indexedColor[];
	static GLushort indicies[];

	void DrawCubeArray();
	void DrawIndexedCube();
};


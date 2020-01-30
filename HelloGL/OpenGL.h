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

	void Update();

	void Keyboard(unsigned char key, int x, int y);

private:
	float rotationY = 0.0f;
	float rotationX = 0.0f;

	Camera* mCamera;

	static Vertex indexedVerticies[];
	static Color indexedColor[];
	static GLushort indicies[];

	void DrawIndexedCube();
};


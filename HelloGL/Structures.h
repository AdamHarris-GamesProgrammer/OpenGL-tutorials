#pragma once

#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"

struct Vector3 {
	float x, y, z;

	Vector3(float xValue = 0.0f, float yValue = 0.0f, float  zValue = 0.0f) {
		x = xValue;
		y = yValue;
		z = zValue;
	}
};

struct Rotation {
	float x, y, z;

	Rotation(float xValue = 0.0f, float yValue = 0.0f, float zValue = 0.0f) {
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

struct Mesh {
	Vertex* Vertices;
	Color* Colors;
	GLushort* Indicies;
	int VertexCount, ColorCount, IndexCount;
};

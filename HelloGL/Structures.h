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

struct Vector4 {
	float x, y, z, w;

	Vector4(float xValue = 0.0f, float yValue = 0.0f, float zValue = 0.0f, float wValue = 0.0f) {
		x = xValue;
		y = yValue;
		z = zValue;
		w = wValue;
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

struct TexCoord {
	GLfloat u, v;
};

struct Mesh {
	Vertex* Vertices;
	Vector3* Normal;

	GLushort* Indicies;

	TexCoord* TexCoords;
	int VertexCount, NormalCount, IndexCount, TexCoordCount;
};

struct Lighting {
	Vector4 Ambient;
	Vector4 Diffuse;
	Vector4 Specular;
};

struct Material {
	Vector4 Ambient;
	Vector4 Diffuse;
	Vector4 Specular;

	GLfloat Shininess;
};
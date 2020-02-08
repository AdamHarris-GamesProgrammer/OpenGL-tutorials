#pragma once
#include<Windows.h>
#include "gl/GL.h"
#include "gl/GLU.h"
#include "GL/freeglut.h"
#include "Structures.h"

class Cube
{
public:
	Cube();
	Cube(Vector3 position) : mPosition(position) {}
	Cube(float xPos, float yPos, float zPos);
	~Cube();

	void Draw();
	void Update();

	Rotation GetRotation() { return mRotation; }
	void SetRotation(Rotation newRotation) { mRotation = newRotation; }
	static bool Load(const char* path);

private:
	static Vertex* indexedVertices;
	static Color* indexedColor;
	static GLushort* indicies;

	static Rotation mRotation;

	static int numVerticies, numColors, numIndicies;

	Vector3 mPosition;
};


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

private:
	static Vertex indexedVertices[];
	static Color indexedColor[];
	static GLushort indicies[];

	static Rotation mRotation;

	Vector3 mPosition;
};


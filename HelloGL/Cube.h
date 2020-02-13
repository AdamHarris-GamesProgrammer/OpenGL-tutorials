#pragma once
#include<Windows.h>
#include "gl/GL.h"
#include "gl/GLU.h"
#include "GL/freeglut.h"

#include "Structures.h"
#include "SceneObject.h"

class Cube : public SceneObject
{
public:
	Cube(Mesh* mesh, float xPos, float yPos, float zPos);
	~Cube();

	void Draw() override;
	void Update() override;

	Rotation GetRotation() { return mRotation; }
	void SetRotation(Rotation newRotation) { mRotation = newRotation; }

private:

	static Rotation mRotation;


	Vector3 mPosition;
};


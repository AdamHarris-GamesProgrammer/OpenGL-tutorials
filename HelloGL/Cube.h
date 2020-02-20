#pragma once
#include<Windows.h>
#include "gl/GL.h"
#include "gl/GLU.h"
#include "GL/freeglut.h"

#include "Structures.h"
#include "SceneObject.h"
#include "Texture2D.h"

class Cube : public SceneObject
{
public:
	Cube(Mesh* mesh, Texture2D* texutre,  float xPos, float yPos, float zPos);
	~Cube();

	void Draw() override;
	void Update() override;

	Rotation GetRotation() { return mRotation; }
	void SetRotation(Rotation newRotation) { mRotation = newRotation; }

private:

	static Rotation mRotation;


	Vector3 mPosition;
};


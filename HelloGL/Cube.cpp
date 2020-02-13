#include "Cube.h"
#include <fstream>
#include <iostream>

Cube::Cube(Mesh* mesh, float xPos, float yPos, float zPos) : SceneObject(mesh)
{
	mPosition.x = xPos;
	mPosition.y = yPos;
	mPosition.z = zPos;
}

Cube::~Cube()
{

}

void Cube::Draw()
{
	if (mMesh->Vertices != nullptr && mMesh->Colors != nullptr && mMesh->Indicies != nullptr)
	{
		glPushMatrix();

		glTranslatef(mPosition.x, mPosition.y, mPosition.z);

		glRotatef(mRotation.x, 1.0f, 0.0f, 0.0f);
		glRotatef(mRotation.y, 0.0f, 1.0f, 0.0f);
		glRotatef(mRotation.z, 0.0f, 0.0f, 1.0f);

		glBegin(GL_TRIANGLES);
		for (int i = 0; i < mMesh->IndexCount; i++)
		{
			glColor3fv(&mMesh->Colors[mMesh->Indicies[i]].r);
			glVertex3fv(&mMesh->Vertices[mMesh->Indicies[i]].x);
		}
		glEnd();

		glPopMatrix();
	}

}

void Cube::Update()
{
	mRotation.x += 0.01f;
	mRotation.y += 0.01f;
	mRotation.z += 0.01f;

	if (mRotation.x > 360.0f) {
		mRotation.x = 0.0f;
	}
	if (mRotation.y > 360.0f) {
		mRotation.y = 0.0f;
	}
	if (mRotation.z > 360.0f) {
		mRotation.z = 0.0f;
	}

	//mRotation.x += (rand() % 10) / 100.0f;
	//mRotation.y += (rand() % 10) / 100.0f;
	//mRotation.z += (rand() % 10) / 100.0f;
}

Rotation Cube::mRotation = { 0,0,0 };
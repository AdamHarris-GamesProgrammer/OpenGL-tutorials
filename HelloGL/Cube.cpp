#include "Cube.h"

#include <ctime>
#include <fstream>
#include <iostream>

Cube::Cube(Mesh* mesh, Texture2D* texture, float xPos, float yPos, float zPos) : SceneObject(mesh, texture)
{
	mPosition.x = xPos;
	mPosition.y = yPos;
	mPosition.z = zPos;

	mMaterial = new Material();
	mMaterial->Ambient.x = (rand() % 10) / 100.0f; mMaterial->Ambient.y = (rand() % 10) / 100.0f; mMaterial->Ambient.z = (rand() % 10) / 100.0f; mMaterial->Ambient.w = 1.0f;
	mMaterial->Diffuse.x = 0.05f; mMaterial->Diffuse.y = 0.05f; mMaterial->Diffuse.z = 0.05f; mMaterial->Diffuse.w = 1.0f;
	mMaterial->Specular.x = 1.0f; mMaterial->Specular.y = 1.0f; mMaterial->Specular.z = 1.0f; mMaterial->Specular.w = 1.0f;
	mMaterial->Shininess = 100.0f;
}

Cube::~Cube()
{

}

void Cube::Draw()
{
	if (mMesh->Vertices != nullptr && mMesh->Normal != nullptr && mMesh->Indicies != nullptr)
	{
		glBindTexture(GL_TEXTURE_2D, mTexture->GetID());

		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);

		glPushMatrix();

		glTranslatef(mPosition.x, mPosition.y, mPosition.z);

		glRotatef(mRotation.x, 1.0f, 0.0f, 0.0f);
		glRotatef(mRotation.y, 0.0f, 1.0f, 0.0f);
		glRotatef(mRotation.z, 0.0f, 0.0f, 1.0f);

		glBegin(GL_TRIANGLES);
		for (int i = 0; i < mMesh->IndexCount; i++)
		{
			glMaterialfv(GL_FRONT, GL_AMBIENT, &(mMaterial->Ambient.x));
			glMaterialfv(GL_FRONT, GL_DIFFUSE, &(mMaterial->Diffuse.x));
			glMaterialfv(GL_FRONT, GL_SPECULAR, &(mMaterial->Specular.x));
			glMaterialf(GL_FRONT, GL_SHININESS, mMaterial->Shininess);

			glTexCoord2fv(&mMesh->TexCoords[mMesh->Indicies[i]].u);
			glNormal3fv(&mMesh->Normal[mMesh->Indicies[i]].x);
			glVertex3fv(&mMesh->Vertices[mMesh->Indicies[i]].x);
		}
		glEnd();

		glPopMatrix();

	}

}

void Cube::Update()
{
	//mRotation.y += 0.01f;
	//mRotation.y += 0.01f;
	//mRotation.z += 0.01f;

	if (mRotation.x > 360.0f) {
		mRotation.x = 0.0f;
	}
	if (mRotation.y > 360.0f) {
		mRotation.y = 0.0f;
	}
	if (mRotation.z > 360.0f) {
		mRotation.z = 0.0f;
	}
	
	srand(time(0));
	mRotation.x += (rand() % 10) / 1000.0f;
	mRotation.y += (rand() % 10) / 1000.0f;
	mRotation.z += (rand() % 10) / 1000.0f;
}

Rotation Cube::mRotation = { 0,0,0 };
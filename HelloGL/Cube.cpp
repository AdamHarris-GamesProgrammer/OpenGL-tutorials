#include "Cube.h"
#include <fstream>
#include <iostream>

Cube::Cube(Mesh* mesh, Texture2D* texture, float xPos, float yPos, float zPos) : SceneObject(mesh, texture)
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
			glTexCoord2fv(&mMesh->TexCoords[mMesh->Indicies[i]].u);
			glColor3fv(&mMesh->Colors[mMesh->Indicies[i]].r);
			glVertex3fv(&mMesh->Vertices[mMesh->Indicies[i]].x);
		}
		glEnd();

		glPopMatrix();




		//glBindTexture(GL_TEXTURE_2D, mTexture->GetID());
		//glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		//glEnableClientState(GL_VERTEX_ARRAY);
		//glEnableClientState(GL_COLOR_ARRAY);
		//glVertexPointer(3, GL_FLOAT, 0, mMesh->Vertices);
		//glColorPointer(3, GL_FLOAT, 0, mMesh->Colors);
		//glTexCoordPointer(2, GL_FLOAT, 0, mMesh->TexCoords);
		//glPushMatrix();
		//glTranslatef(mPosition.x, mPosition.y, mPosition.z);

		//glRotatef(mRotation.x, 1.0f, 0.0f, 0.0f);
		//glRotatef(mRotation.y, 0.0f, 1.0f, 0.0f);
		//glRotatef(mRotation.z, 0.0f, 0.0f, 1.0f);
		//glBegin(GL_TRIANGLES);
		////glDrawElements(GL_TRIANGLES, mMesh->IndexCount, GL_UNSIGNED_INT, mMesh->Indicies);
		//glDrawArrays(GL_TRIANGLES, 0, mMesh->IndexCount);
		//glPopMatrix();
		//glEnd();
		//glDisableClientState(GL_TEXTURE_COORD_ARRAY);
		//glDisableClientState(GL_COLOR_ARRAY);
		//glDisableClientState(GL_VERTEX_ARRAY);

	}

}

void Cube::Update()
{
	mRotation.y += 0.01f;
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

	//mRotation.x += (rand() % 10) / 100.0f;
	//mRotation.y += (rand() % 10) / 100.0f;
	//mRotation.z += (rand() % 10) / 100.0f;
}

Rotation Cube::mRotation = { 0,0,0 };
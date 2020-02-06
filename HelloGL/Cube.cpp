#include "Cube.h"

Cube::Cube()
{

}

Cube::Cube(float xPos, float yPos, float zPos)
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
	glPushMatrix();

	glTranslatef(mPosition.x, mPosition.y, mPosition.z);

	glRotatef(mRotation.x, 1.0f, 0.0f, 0.0f);
	glRotatef(mRotation.y, 0.0f, 1.0f, 0.0f);
	glRotatef(mRotation.z, 0.0f, 0.0f, 1.0f);

	glBegin(GL_TRIANGLES);
	for (int i = 0; i < 36; i++) {
		glColor3fv(&indexedColor[indicies[i]].r);
		glVertex3fv(&indexedVertices[indicies[i]].x);
	}
	glEnd();

	glPopMatrix();
}

void Cube::Update()
{
	mRotation.x += 0.01f;
	mRotation.y += 0.01f;
	mRotation.z += 0.01f;
}

GLushort Cube::indicies[] = { 0, 1, 2,  2, 3, 0,      // front
				0, 3, 4,  4, 5, 0,      // right
				0, 5, 6,  6, 1, 0,      // top
				1, 6, 7,  7, 2, 1,      // left
				7, 4, 3,  3, 2, 7,      // bottom
				4, 7, 6,  6, 5, 4 };    // back

Color Cube::indexedColor[] = { 1, 1, 1,   1, 1, 0,   // v0,v1,
				1, 0, 0,   1, 0, 1,   // v2,v3
				0, 0, 1,   0, 1, 1,   // v4,v5
				0, 1, 0,   0, 0, 0 }; //v6,v7

Vertex Cube::indexedVertices[] = { 1, 1, 1,  -1, 1, 1,  // v0,v1,
				-1,-1, 1,   1,-1, 1,   // v2,v3
				1,-1,-1,   1, 1,-1,    // v4,v5
				-1, 1,-1,   -1,-1,-1 }; // v6,v7

Rotation Cube::mRotation = { 0,0,0 };
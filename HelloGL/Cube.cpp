#include "Cube.h"
#include <fstream>
#include <iostream>

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
	if (indexedVertices != nullptr && indexedColor != nullptr && indicies != nullptr)
	{
		glPushMatrix();

		glTranslatef(mPosition.x, mPosition.y, mPosition.z);

		glRotatef(mRotation.x, 1.0f, 0.0f, 0.0f);
		glRotatef(mRotation.y, 0.0f, 1.0f, 0.0f);
		glRotatef(mRotation.z, 0.0f, 0.0f, 1.0f);

		glBegin(GL_TRIANGLES);
		for (int i = 0; i < 36; i++)
		{
			glColor3fv(&indexedColor[indicies[i]].r);
			glVertex3fv(&indexedVertices[indicies[i]].x);
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
}

bool Cube::Load(const char* path)
{
	std::ifstream inFile;
	inFile.open(path);
	if (!inFile.good()) {
		std::cerr << "Can't open text file " << path << std::endl;
		return false;
	}

	inFile >> numVerticies;
	indexedVertices = new Vertex[numVerticies];
	for (int i = 0; i < numVerticies; i++) {
		inFile >> indexedVertices[i].x;
		inFile >> indexedVertices[i].y;
		inFile >> indexedVertices[i].z;

		std::cout << "X: " << indexedVertices[i].x << " Y: " << indexedVertices[i].y << " Z: " << indexedVertices[i].z << std::endl;
	}

	inFile >> numColors;
	indexedColor = new Color[numColors];
	for (int i = 0; i < numColors; i++) {
		inFile >> indexedColor[i].r;
		inFile >> indexedColor[i].g;
		inFile >> indexedColor[i].b;

		std::cout << "R: " << indexedColor[i].r << " G: " << indexedColor[i].g << " B: " << indexedColor[i].b << std::endl;
	}

	inFile >> numIndicies;
	indicies = new GLushort[numIndicies];
	for (int i = 0; i < numIndicies; i++) {
		inFile >> indicies[i];

		std::cout << "Indices: " << indicies[i] << std::endl;
	}

	inFile.close();
}

GLushort* Cube::indicies = nullptr;

Color* Cube::indexedColor = nullptr;

Vertex* Cube::indexedVertices = nullptr;

Rotation Cube::mRotation = { 0,0,0 };

int Cube::numVerticies = 0;
int Cube::numColors = 0;
int Cube::numIndicies = 0;
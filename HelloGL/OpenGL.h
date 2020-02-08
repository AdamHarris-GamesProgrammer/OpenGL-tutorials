#pragma once

#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"


#include "GLUTCallback.h"
#include "Structures.h"

#define REFRESH_RATE 16



class OpenGL
{
public:
	OpenGL(int argc, char* argv[]);
	~OpenGL();

	void Display();

	void Update();

	void Keyboard(unsigned char key, int x, int y);

private:
	Camera* mCamera;

	class Cube* cube[];
	//class Cube* cubeFromFile;
};


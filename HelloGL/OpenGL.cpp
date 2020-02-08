#include "OpenGL.h"
#include <ctime>
#include <random>

#include<iostream>

#include "Cube.h"

OpenGL::OpenGL(int argc, char* argv[])
{
	mCamera = new Camera();
	mCamera->eye.x = 0.0f; mCamera->eye.y = 0.0f; mCamera->eye.z = 1.0f;
	mCamera->center.x = 0.0f; mCamera->center.y = 0.0f; mCamera->center.z = 0.0f;
	mCamera->up.x = 0.0f; mCamera->up.y = 1.0f; mCamera->up.z = 0.0f;

	GLUTCallback::Init(this);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 800);
	//glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("Simple OpenGL Program");
	glutDisplayFunc(GLUTCallback::Display);
	glutTimerFunc(REFRESH_RATE, GLUTCallback::Timer, REFRESH_RATE);
	glutKeyboardFunc(GLUTCallback::Keyboard);

	glEnable(GL_DEPTH_TEST);

	glMatrixMode(GL_PROJECTION);

	glViewport(0, 0, 800, 800);
	gluPerspective(45, 1, 0.1, 1000);

	glMatrixMode(GL_MODELVIEW);



	glEnable(GL_CULL_FACE);
	
	glCullFace(GL_BACK);

	Cube::Load("Assets/cube.txt");
	for (int i = 0; i < 200; i++) {
		cube[i] = new Cube(((rand() % 400) / 10.0f) - 20.0f, ((rand() % 200) / 10.0f) - 10.0f, -(rand() % 1000) / 10.0f);
	}

	//cubeFromFile = new Cube();
	//cubeFromFile->Load("Assets/cube.txt");


	glutMainLoop();
}

OpenGL::~OpenGL()
{
	delete mCamera;
}

void OpenGL::Display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClear(GL_DEPTH_BUFFER_BIT);

	for (int i = 0; i < 200; i++) {
		cube[i]->Draw();
	}

	//cubeFromFile->Draw();

	glFlush();
	glutSwapBuffers();
}

void OpenGL::Update()
{
	glLoadIdentity();
	gluLookAt(mCamera->eye.x, mCamera->eye.y, mCamera->eye.z, mCamera->center.x, mCamera->center.y, mCamera->center.z, mCamera->up.x, mCamera->up.y, mCamera->up.z);

	for (int i = 0; i < 200; i++) {
		cube[i]->Update();
	}
	//cubeFromFile->Update();

	glTranslatef(0.0f, 0.0f, -5.0f);
	glutPostRedisplay();
}

void OpenGL::Keyboard(unsigned char key, int x, int y)
{

}


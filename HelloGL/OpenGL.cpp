#include "OpenGL.h"
#include <ctime>
#include <random>

#include<iostream>

#include "Cube.h"

OpenGL::OpenGL(int argc, char* argv[])
{
	srand(time(0));
	InitOpenGL(argc,argv);
	InitObjects();
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

	for (int i = 0; i < 1000; i++) {
		sceneObjects[i]->Draw();
	}


	glFlush();
	glutSwapBuffers();
}

void OpenGL::Update()
{
	glLoadIdentity();
	gluLookAt(mCamera->eye.x, mCamera->eye.y, mCamera->eye.z, mCamera->center.x, mCamera->center.y, mCamera->center.z, mCamera->up.x, mCamera->up.y, mCamera->up.z);

	for (int i = 0; i < 1000; i++) {
		sceneObjects[i]->Update();
	}
	//cubeFromFile->Update();

	glTranslatef(0.0f, 0.0f, -5.0f);
	glutPostRedisplay();
}

void OpenGL::Keyboard(unsigned char key, int x, int y)
{

}

void OpenGL::InitOpenGL(int argc, char* argv[])
{
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
}

void OpenGL::InitObjects()
{
	mCamera = new Camera();
	mCamera->eye.x = 0.0f; mCamera->eye.y = 0.0f; mCamera->eye.z = 1.0f;
	mCamera->center.x = 0.0f; mCamera->center.y = 0.0f; mCamera->center.z = 0.0f;
	mCamera->up.x = 0.0f; mCamera->up.y = 1.0f; mCamera->up.z = 0.0f;

	Mesh* cubeMesh = MeshLoader::Load("Assets/pyramid.txt");
	Mesh* pyramidMesh = MeshLoader::Load("Assets/cube.txt");

	for (int i = 0; i < 500; i++) {
		sceneObjects[i] = new Cube(cubeMesh, ((rand() % 400) / 10.0f) - 20.0f, ((rand() % 200) / 10.0f) - 10.0f, -(rand() % 1000) / 10.0f);
	}

	for (int i = 500; i < 1000; i++) {
		sceneObjects[i] = new Cube(pyramidMesh, ((rand() % 400) / 10.0f) - 20.0f, ((rand() % 200) / 10.0f) - 10.0f, -(rand() % 1000) / 10.0f);

	}
}


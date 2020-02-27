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
	InitLighting();

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

	for (int i = 0; i < 500; i++) {
		sceneObjects[i]->Draw();
	}


	glFlush();
	glutSwapBuffers();
}

void OpenGL::Update()
{
	glLoadIdentity();
	gluLookAt(mCamera->eye.x, mCamera->eye.y, mCamera->eye.z, mCamera->center.x, mCamera->center.y, mCamera->center.z, mCamera->up.x, mCamera->up.y, mCamera->up.z);
	glLightfv(GL_LIGHT0, GL_AMBIENT, &(mLightData->Ambient.x));
	glLightfv(GL_LIGHT0, GL_DIFFUSE, &(mLightData->Diffuse.x));
	glLightfv(GL_LIGHT0, GL_SPECULAR, &(mLightData->Specular.x));
	glLightfv(GL_LIGHT0, GL_POSITION, &(mLightPosition->x));

	for (int i = 0; i < 500; i++) {
		sceneObjects[i]->Update();
	}

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
	glutCreateWindow("Simple OpenGL Program");
	glutDisplayFunc(GLUTCallback::Display);
	glutTimerFunc(REFRESH_RATE, GLUTCallback::Timer, REFRESH_RATE);
	glutKeyboardFunc(GLUTCallback::Keyboard);

	

	glMatrixMode(GL_PROJECTION);

	glViewport(0, 0, 800, 800);
	gluPerspective(45, 1, 0.1, 1000);

	glMatrixMode(GL_MODELVIEW);

	glEnable(GL_TEXTURE_2D);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glEnable(GL_NORMAL_ARRAY);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glCullFace(GL_BACK);
}

void OpenGL::InitObjects()
{
	mCamera = new Camera();
	mCamera->eye.x = 0.0f; mCamera->eye.y = 0.0f; mCamera->eye.z = 1.0f;
	mCamera->center.x = 0.0f; mCamera->center.y = 0.0f; mCamera->center.z = 0.0f;
	mCamera->up.x = 0.0f; mCamera->up.y = 1.0f; mCamera->up.z = 0.0f;

	Mesh* cubeMesh = MeshLoader::Load("Assets/cube.txt");
	Texture2D* cubeTexture = new Texture2D();
	cubeTexture->Load((char*)"Assets/Penguins.raw", 512, 512);

	for (int i = 0; i < 500; i++) {
		sceneObjects[i] = new Cube(cubeMesh, cubeTexture, ((rand() % 400) / 10.0f) - 20.0f, ((rand() % 200) / 10.0f) - 10.0f, -(rand() % 1000) / 10.0f);
	}

}

void OpenGL::InitLighting()
{
	mLightPosition = new Vector4(0.0f, 0.0f, 1.0f, 0.0f);
	mLightData = new Lighting();
	mLightData->Ambient.x = 0.2f;
	mLightData->Ambient.y = 0.2f;
	mLightData->Ambient.z = 0.2f;
	mLightData->Ambient.w = 1.0f;
	mLightData->Diffuse.x = 0.8f;
	mLightData->Diffuse.y = 0.8f;
	mLightData->Diffuse.z = 0.8f;
	mLightData->Diffuse.w = 1.0f;
	mLightData->Specular.x = 0.2f;
	mLightData->Specular.y = 0.2f;
	mLightData->Specular.z = 0.2f;
	mLightData->Specular.w = 1.0f;
}


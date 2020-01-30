#include "OpenGL.h"
#include "Colors.h"
#include <ctime>
#include <random>

#include<iostream>

OpenGL::OpenGL(int argc, char* argv[])
{
	rotation = 0.0f;

	mCamera = new Camera();
	mCamera->eye.x = 0.0f; mCamera->eye.y = 0.0f; mCamera->eye.z = 1.0f;
	mCamera->center.x = 0.0f; mCamera->center.y = 0.0f; mCamera->center.z = 0.0f;
	mCamera->up.x = 0.0f; mCamera->up.y = 1.0f; mCamera->up.z = 0.0f;

	GLUTCallback::Init(this);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);

	glutInitWindowSize(800, 800);
	glutCreateWindow("Simple OpenGL Program");
	glutDisplayFunc(GLUTCallback::Display);
	glutTimerFunc(REFRESH_RATE, GLUTCallback::Timer, REFRESH_RATE);
	glutKeyboardFunc(GLUTCallback::Keyboard);

	glMatrixMode(GL_PROJECTION);

	glViewport(0, 0, 800, 800);
	gluPerspective(45, 1, 0, 1000);

	glMatrixMode(GL_MODELVIEW);

	glutMainLoop();
}

OpenGL::~OpenGL()
{
	delete mCamera;
}

void OpenGL::Display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	glPushMatrix();
	glRotatef(rotation, 0.0f, -1.0f, 0.0f);
	/*DrawPolygon(squareA);*/

	glutWireCube(1.3);


	glPopMatrix();
	glFlush();
	glutSwapBuffers();
}


void OpenGL::DrawPolygon(float points[4][2])
{
	glBegin(GL_POLYGON);
	{
		glVertex2f(points[0][0], points[0][1]);
		glVertex2f(points[1][0], points[1][1]);
		glVertex2f(points[2][0], points[2][1]);
		glVertex2f(points[3][0], points[3][1]);
	}
	glEnd();
}

void OpenGL::DrawPolygon(float points[4][2], float r, float g, float b, float a)
{
	glBegin(GL_POLYGON);
	{
		glColor4f(r,g,b,a);
		glVertex2f(points[0][0], points[0][1]);
		glVertex2f(points[1][0], points[1][1]);
		glVertex2f(points[2][0], points[2][1]);
		glVertex2f(points[3][0], points[3][1]);
	}
	glEnd();
}

void OpenGL::DrawTriangle(float points[3][2])
{
	glBegin(GL_TRIANGLES);
	{
		glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
		glVertex2f(points[0][0], points[0][1]);
		glVertex2f(points[1][0], points[1][1]);
		glColor4f(0.0f, 0.0f, 1.0f, 0.0f);
		glVertex2f(points[2][0], points[2][1]);
	}
	glEnd();
}

void OpenGL::Update()
{
	glLoadIdentity();
	gluLookAt(mCamera->eye.x, mCamera->eye.y, mCamera->eye.z, mCamera->center.x, mCamera->center.y, mCamera->center.z, mCamera->up.x, mCamera->up.y, mCamera->up.z);


	glTranslatef(0.0f, 0.0f, -5.0f);
	glutPostRedisplay();


	if (rotation >= 360.0f) {
		rotation = 0.0f;
	}




}

void OpenGL::Keyboard(unsigned char key, int x, int y)
{
	if (key == 'd') {
		rotation += 0.5f;
	}
	else if (key == 'a') {
		rotation -= 0.5f;
	}
	else if (key == 'w') {
		mCamera->eye.z += 0.1f;
	}
	else if (key == 's') {
		mCamera->eye.z -= 0.1f;
	}

	
}

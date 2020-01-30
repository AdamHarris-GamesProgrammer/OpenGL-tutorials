#include "OpenGL.h"
#include "Colors.h"
#include <ctime>
#include <random>

#include<iostream>

Vertex OpenGL::verticies[] = { 1, 1, 1,  -1, 1, 1,  -1,-1, 1,      // v0-v1-v2 (front)
			-1,-1, 1,   1,-1, 1,   1, 1, 1,      // v2-v3-v0

			1, 1, 1,   1,-1, 1,   1,-1,-1,      // v0-v3-v4 (right)
			1,-1,-1,   1, 1,-1,   1, 1, 1,      // v4-v5-v0

			1, 1, 1,   1, 1,-1,  -1, 1,-1,      // v0-v5-v6 (top)
			-1, 1,-1,  -1, 1, 1,   1, 1, 1,      // v6-v1-v0

			-1, 1, 1,  -1, 1,-1,  -1,-1,-1,      // v1-v6-v7 (left)
			-1,-1,-1,  -1,-1, 1,  -1, 1, 1,      // v7-v2-v1

			-1,-1,-1,   1,-1,-1,   1,-1, 1,      // v7-v4-v3 (bottom)
			1,-1, 1,  -1,-1, 1,  -1,-1,-1,      // v3-v2-v7

			1,-1,-1,  -1,-1,-1,  -1, 1,-1,      // v4-v7-v6 (back)
			-1, 1,-1,   1, 1,-1,   1,-1,-1 };    // v6-v5-v4

Color OpenGL::colors[] = { 1, 1, 1,   1, 1, 0,   1, 0, 0,      // v0-v1-v2 (front)
				1, 0, 0,   1, 0, 1,   1, 1, 1,      // v2-v3-v0

				1, 1, 1,   1, 0, 1,   0, 0, 1,      // v0-v3-v4 (right)
				0, 0, 1,   0, 1, 1,   1, 1, 1,      // v4-v5-v0

				1, 1, 1,   0, 1, 1,   0, 1, 0,      // v0-v5-v6 (top)
				0, 1, 0,   1, 1, 0,   1, 1, 1,      // v6-v1-v0

				1, 1, 0,   0, 1, 0,   0, 0, 0,      // v1-v6-v7 (left)
				0, 0, 0,   1, 0, 0,   1, 1, 0,      // v7-v2-v1

				0, 0, 0,   0, 0, 1,   1, 0, 1,      // v7-v4-v3 (bottom)
				1, 0, 1,   1, 0, 0,   0, 0, 0,      // v3-v2-v7

				0, 0, 1,   0, 0, 0,   0, 1, 0,      // v4-v7-v6 (back)
				0, 1, 0,   0, 1, 1,   0, 0, 1 };    // v6-v5-v4

Vertex OpenGL::indexedVerticies[] = { 1, 1, 1,  -1, 1, 1,  // v0,v1,
				-1,-1, 1,   1,-1, 1,   // v2,v3
				1,-1,-1,   1, 1,-1,    // v4,v5
				-1, 1,-1,   -1,-1,-1 }; // v6,v7

Color OpenGL::indexedColor[] = { 1, 1, 1,   1, 1, 0,   // v0,v1,
				1, 0, 0,   1, 0, 1,   // v2,v3
				0, 0, 1,   0, 1, 1,   // v4,v5
				0, 1, 0,   0, 0, 0 }; //v6,v7

GLushort OpenGL::indicies[] = { 0, 1, 2,  2, 3, 0,      // front
				0, 3, 4,  4, 5, 0,      // right
				0, 5, 6,  6, 1, 0,      // top
				1, 6, 7,  7, 2, 1,      // left
				7, 4, 3,  3, 2, 7,      // bottom
				4, 7, 6,  6, 5, 4 };    // back


OpenGL::OpenGL(int argc, char* argv[])
{
	rotationY = 0.0f;
	rotationX = 0.0f;

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

	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

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
	glRotatef(rotationY, 0.0f, -1.0f, 0.0f);
	glRotatef(rotationX, -1.0f, 0.0f, 0.0f);

	DrawIndexedCube();

	glPopMatrix();
	glFlush();
	glutSwapBuffers();
}


void OpenGL::DrawCubeArray()
{
	glPushMatrix();
	glBegin(GL_TRIANGLES);
	for (int i = 0; i < 36; i++) {
		glColor3fv(&colors[i].r);
		glVertex3fv(&verticies[i].x);
	}
	glEnd();

	glPopMatrix();
}

void OpenGL::DrawIndexedCube()
{
	glPushMatrix();

	glBegin(GL_TRIANGLES);
	for (int i = 0; i < 36; i++) {
		glColor3fv(&indexedColor[indicies[i]].r);
		glVertex3fv(&indexedVerticies[indicies[i]].x);
	}
	glEnd();

	glPopMatrix();
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

void OpenGL::DrawCube()
{
	glBegin(GL_TRIANGLES);
	//face 1
	glColor3f(1, 1, 1);
	glVertex3f(1, 1, 1);
	glColor3f(1, 1, 0);
	glVertex3f(-1, 1, 1);
	glColor3f(1, 0, 0);
	glVertex3f(-1, -1, 1);
	//face 2
	glColor3f(1, 0, 0);
	glVertex3f(-1, -1, 1);
	glColor3f(1, 0, 1);
	glVertex3f(1, -1, 1);
	glColor3f(1, 1, 1);
	glVertex3f(1, 1, 1);
	//face 3
	glColor3f(1, 1, 1);
	glVertex3f(1, 1, 1);
	glColor3f(0, 1, 1);
	glVertex3f(1, 1, -1);
	glColor3f(1, 1, 1);
	glVertex3f(1, 1, 1);
	//face 4
	glColor3f(0, 0, 1);
	glVertex3f(1, -1, -1);
	glColor3f(0, 1, 1);
	glVertex3f(1, 1, -1);
	glColor3f(1, 1, 1);
	glVertex3f(1, 1, 1);
	//face 5
	glColor3f(1, 1, 1);
	glVertex3f(1, 1, 1);
	glColor3f(0, 1, 1);
	glVertex3f(1, 1, -1);
	glColor3f(0, 1, 0);
	glVertex3f(-1, 1, -1);
	//face 6
	glColor3f(0,1,0);
	glVertex3f(-1, 1, -1);
	glColor3f(1, 1, 0);
	glVertex3f(-1, 1, 1);
	glColor3f(1, 1, 1);
	glVertex3f(1, 1, 1);
	//face 7
	glColor3f(1, 1, 0);
	glVertex3f(-1, 1, 1);
	glColor3f(0, 1, 0);
	glVertex3f(-1, 1, -1);
	glColor3f(0, 0, 0);
	glVertex3f(-1, -1, -1);
	//face 8
	glColor3f(0, 0, 0);
	glVertex3f(-1, -1, -1);
	glColor3f(1, 0, 0);
	glVertex3f(-1, -1, 1);
	glColor3f(1, 1, 0);
	glVertex3f(-1, 1, 1);
	//face 9
	glColor3f(1, 0, 1);
	glVertex3f(-1, -1, -1);
	glColor3f(0, 0, 1);
	glVertex3f(1, -1, -1);
	glColor3f(1, 0, 1);
	glVertex3f(1, -1, 1);
	//face 10
	glColor3f(1, 0, 1);
	glVertex3f(1, -1, 1);
	glColor3f(1, 0, 0);
	glVertex3f(-1, -1, 1);
	glColor3f(0, 0, 0);
	glVertex3f(-1, -1, -1);
	//face 11
	glColor3f(0, 0, 1);
	glVertex3f(1, -1, -1);
	glColor3f(0, 0, 0);
	glVertex3f(-1, -1, -1);
	glColor3f(0, 1, 0);
	glVertex3f(-1, 1, -1);
	//face 12
	glColor3f(0, 1, 0);
	glVertex3f(-1, 1, -1);
	glColor3f(0, 1, 1);
	glVertex3f(1, 1, -1);
	glColor3f(0, 0, 1);
	glVertex3f(1, -1, -1);

	glEnd();
}

void OpenGL::Update()
{
	glLoadIdentity();
	gluLookAt(mCamera->eye.x, mCamera->eye.y, mCamera->eye.z, mCamera->center.x, mCamera->center.y, mCamera->center.z, mCamera->up.x, mCamera->up.y, mCamera->up.z);


	glTranslatef(0.0f, 0.0f, -5.0f);
	glutPostRedisplay();


	if (rotationY >= 360.0f) {
		rotationY = 0.0f;
	}
	if (rotationX >= 360.0f) {
		rotationX = 0.0f;
	}




}

void OpenGL::Keyboard(unsigned char key, int x, int y)
{
	if (key == 'd') {
		rotationY += 0.5f;
	}
	else if (key == 'a') {
		rotationY -= 0.5f;
	}
	else if (key == 'w') {
		rotationX -= 0.5f;
	}
	else if (key == 's') {
		rotationX += 0.5f;
	}

	
}


#include "OpenGL.h"
#include "Colors.h"
#include <ctime>
#include <random>

OpenGL::OpenGL(int argc, char* argv[])
{
	std::random_device rd;
	std::mt19937 gen(rd());

	srand(static_cast <unsigned> (time(0)));
	for (int square = 0; square < 6; square++) {
		for (int point = 0; point < 4; point++) {
			std::uniform_real_distribution<> dis(-1.0, 1.0);
			squaresArray[square][point][0] = dis(gen);
			squaresArray[square][point][1] = dis(gen);
		}
	}

	backgroundColor[0] = (rand()) / static_cast <float> (RAND_MAX), static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	backgroundColor[1] = (rand()) / static_cast <float> (RAND_MAX), static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	backgroundColor[2] = (rand()) / static_cast <float> (RAND_MAX), static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	backgroundColor[3] = (rand()) / static_cast <float> (RAND_MAX), static_cast <float> (rand()) / static_cast <float> (RAND_MAX);


	GLUTCallback::Init(this);
	glutInit(&argc, argv);
	glutInitWindowSize(800, 800);
	glutCreateWindow("Simple OpenGL Program");
	glutDisplayFunc(GLUTCallback::Display);
	glutMainLoop();
}

void OpenGL::Display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	glClearColor(backgroundColor[0],backgroundColor[1],backgroundColor[2], backgroundColor[3]);
	for (int square = 0; square < 6; square++) {
		glBegin(GL_POLYGON);
		{
			glColor4f(static_cast <float> (rand()) / static_cast <float> (RAND_MAX), static_cast <float> (rand()) / static_cast <float> (RAND_MAX), static_cast <float> (rand()) / static_cast <float> (RAND_MAX),static_cast <float> (rand()) / static_cast <float> (RAND_MAX));
			glVertex2f(squaresArray[square][0][0], squaresArray[square][0][1]);
			glVertex2f(squaresArray[square][1][0], squaresArray[square][1][1]);
			glVertex2f(squaresArray[square][2][0], squaresArray[square][2][1]);
			glVertex2f(squaresArray[square][3][0], squaresArray[square][3][1]);

		}
		glEnd();
	}

	glFlush();
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

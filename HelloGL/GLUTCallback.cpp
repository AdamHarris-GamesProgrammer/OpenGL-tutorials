#include "GLUTCallback.h"
#include "OpenGL.h"

namespace GLUTCallback {
	namespace {
		OpenGL* helloGL = nullptr;
	}

	void Init(OpenGL* gl) {
		helloGL = gl;
	}

	void Display() {
		if (helloGL != nullptr) {
			helloGL->Display();
		}
	}

	void Timer(int preferredRefresh)
	{
		if (helloGL != nullptr) {
			int updateTime = glutGet(GLUT_ELAPSED_TIME);
			helloGL->Update();

			updateTime = glutGet(GLUT_ELAPSED_TIME) - updateTime;
			glutTimerFunc(preferredRefresh - updateTime, GLUTCallback::Timer, preferredRefresh - updateTime);
		}
	}

	void Keyboard(unsigned char key, int x, int y)
	{
		if (helloGL != nullptr) {
			helloGL->Keyboard(key, x, y);
		}
	}

}

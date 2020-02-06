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
		helloGL->Update();

		glutTimerFunc(preferredRefresh, GLUTCallback::Timer, preferredRefresh);

	}

	void Keyboard(unsigned char key, int x, int y)
	{
		if (helloGL != nullptr) {
			helloGL->Keyboard(key, x, y);
		}
	}

}

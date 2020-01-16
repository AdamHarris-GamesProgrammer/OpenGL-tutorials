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
}

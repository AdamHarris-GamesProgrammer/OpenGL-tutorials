#pragma once

class OpenGL;

namespace GLUTCallback {
	void Init(OpenGL* gl);

	void Display();
	void Timer(int preferredRefresh);
	void Keyboard(unsigned char key, int x, int y);
}


#pragma once

#include "Structures.h"

class SceneObject
{
public:
	SceneObject(Mesh* mesh);

	virtual ~SceneObject();

	virtual void Update();
	virtual void Draw();
private:

protected:
	Mesh* mMesh;
};


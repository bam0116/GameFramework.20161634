#pragma once

#include "SDLGameObject.h"
#include "InputHandler.h"

class MoveBg : public SDLGameObject
{
public:
	MoveBg(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
};
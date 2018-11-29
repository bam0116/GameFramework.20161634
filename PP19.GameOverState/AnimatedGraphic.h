#pragma once
#include "SDLGameObject.h"

class AnimatedGraphic : public SDLGameObject
{
public:
	AnimatedGraphic(const LoaderParams * pParams, int animSpeed);
	int m_animSpeed;
	virtual void draw();
	virtual void update();
	virtual void clean();
};
#include "MoveBg.h"

MoveBg::MoveBg(const LoaderParams* pParams) : SDLGameObject(pParams)
{
	m_velocity.setY(-2);
}
void MoveBg::draw()
{
	SDLGameObject::draw(); // we now use SDLGameObject
}
void MoveBg::update()
{
	m_velocity.setY(-2);
	if (m_position.getY() == -680)
	{
		m_position.setY(0);
	}
	SDLGameObject::update();
}
void MoveBg::clean()
{
}
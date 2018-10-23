#include "Enemy.h"



void Enemy::update()
{
	Speed = 1;
	if (m_x <= 0)
	{
		Check = 1;
	}
	if (m_x >= 500)
	{
		Check = 0;
	}
	if (Check == 1)
	{
		m_x += Speed;
	}
	else if (Check == 0)
	{
		m_x -= Speed;
	}
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
}
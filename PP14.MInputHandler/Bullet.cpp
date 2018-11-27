#include "Player.h"


Bullet::Bullet(const LoaderParams* pParams) :SDLGameObject(pParams) {}


void Bullet::draw()
{
	SDLGameObject::draw();
}
void Bullet::handleInput()
{

}

void Bullet::update()
{
	m_velocity.setX(2);
	m_velocity.setY(0);
	handleInput();
	m_currentFrame = 0;
	SDLGameObject::update();
}

void Bullet::clean()
{
}
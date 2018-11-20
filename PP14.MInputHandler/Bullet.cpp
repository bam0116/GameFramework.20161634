#include "Bullet.h"

Bullet::Bullet(const LoaderParams* pParams) : SDLGameObject(pParams)
{
}
void Bullet::draw()
{
	SDLGameObject::draw(); // we now use SDLGameObject
}
void Bullet::update()
{
	m_velocity.setX(0);
	m_velocity.setY(0);
	handleInput();
	//m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
	SDLGameObject::update();

}
void Bullet::clean()
{
}
void Bullet::handleInput()
{
	m_velocity.setX(3);
	//Vector2D* vec = TheInputHandler::Instance()->getMousePosition();
	//m_velocity = (*vec - m_position) / 100;
}
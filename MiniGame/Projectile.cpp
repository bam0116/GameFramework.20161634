#include "Projectile.h"

Projectile::Projectile(const LoaderParams* pParams) : SDLGameObject(pParams)
{
	m_velocity.setY(3);
}
void Projectile::draw()
{
	SDLGameObject::draw(); // we now use SDLGameObject
}
void Projectile::update()
{
	m_velocity.setY(5);
	SDLGameObject::update();
}
void Projectile::clean()
{
}
void Projectile::handleInput()
{
}
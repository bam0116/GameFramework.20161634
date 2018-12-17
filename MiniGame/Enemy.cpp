#include "Enemy.h"
#include "Projectile.h"
#include "PlayState.h"

Uint32 startTime, currentTime;
const float StopTime = 1000.0f;

Enemy::Enemy(const LoaderParams* pParams) : SDLGameObject(pParams)
{
	m_velocity.setX(5);
}
void Enemy::draw()
{
	SDLGameObject::draw(); // we now use SDLGameObject
}
void Enemy::update()
{
	m_currentFrame = int(((SDL_GetTicks() / 100) % m_numFrames));
	if (m_position.getX() < 0) {
		m_velocity.setX(5);
	}
	else if (m_position.getX() > 500) {
		m_velocity.setX(-5);
	}
	ShotBullet();
	SDLGameObject::update();
}
void Enemy::clean()
{
}
void Enemy::ShotBullet()
{
		startTime = SDL_GetTicks();

		if (StopTime <= startTime - currentTime)
		{
			Projectile* bullet = new Projectile(new LoaderParams(Enemy::m_position.getX(), Enemy::m_position.getY() + 10, 32, 32, "bullet"));
			PlayState::Instance()->m_bullet.push_back(bullet);
			currentTime = SDL_GetTicks();
		}
}
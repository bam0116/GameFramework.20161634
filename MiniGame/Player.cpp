#include "Player.h"

Player::Player(const LoaderParams* pParams) :SDLGameObject(pParams) {

}


void Player::draw()
{
	SDLGameObject::draw();
}

void Player::handleInput()
{

		if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
		{
			m_velocity.setX(3);
			if (m_position.getX() > 500)
			{
				m_position.setX(500);
			}
		}
		if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
		{
			m_velocity.setX(-3);
			if (m_position.getX() < 0)
			{
				m_position.setX(0);
			}
		}
		if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_Z))
		{
			m_velocity.setX(-3);
			if (m_position.getX() < 0)
			{
				m_position.setX(0);
			}
		}

}

void Player::update()
{
	m_velocity.setX(0);
	m_velocity.setY(0);
	handleInput();
	m_currentFrame = int(((SDL_GetTicks() / 100) % 5));
	SDLGameObject::update();
}

void Player::clean()
{
}
#pragma once
#include "GameObject.h"
#include "Vector2D.h"

class SDLGameObject : public GameObject
{
public:
	SDLGameObject(const LoaderParams* pParams);
	Vector2D& getPosition() { return m_position; }
	int getWidth() { return m_width;}
	int getHeight() { return m_height; }
	virtual void draw();
	virtual void update();
	virtual void clean();
protected:
	int m_width;
	int m_height;
	int m_currentRow;
	int m_currentFrame;
	int m_numFrames = 5;
	std::string m_textureID;
	Vector2D m_position;
	Vector2D m_velocity;
	Vector2D m_acceleration;
};
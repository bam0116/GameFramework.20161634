#pragma once
#include "GameState.h"
#include "Game.h"
#include "MenuState.h"

class GameObject;

class GameWinState : public GameState
{
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return s_winID; }
	static GameWinState* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new GameWinState();
			return s_pInstance;
		}
		return s_pInstance;
	}
private:
	static void s_goToMain();
	static void s_resumePlay();
	static const std::string s_winID;
	static GameWinState* s_pInstance;
	std::vector<GameObject*> m_gameObjects;
};
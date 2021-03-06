#include "PlayState.h"

const std::string PlayState::s_playID = "PLAY";
PlayState* PlayState::s_pInstance = NULL;

void PlayState::update()
{
	if (TheInputHandler::Instance()->isKeyDown(
		SDL_SCANCODE_ESCAPE))
	{
		Game::Instance()->getStateMachine()->changeState(PauseState::Instance());
	}
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}

void PlayState::render()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}

bool PlayState::onEnter()
{
	if (!TheTextureManager::Instance()->load(
		"Assets/helicopter.png", "helicopter",
		Game::Instance()->getRenderer()))
	{
			return false;
	}


	GameObject* player = new Player(
		new LoaderParams(100, 100, 128, 55, "helicopter"));
	m_gameObjects.push_back(player);
	std::cout << "entering PlayState\n";
	return true;
}

bool PlayState::onExit()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();

	TheTextureManager::Instance()->clearFromTextureMap("helicopter");
	std::cout << "exiting PlayState\n";
	return true;
}
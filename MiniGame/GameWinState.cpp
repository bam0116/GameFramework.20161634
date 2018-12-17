#include "GameWinState.h"

const std::string GameWinState::s_winID = "WIN";
GameWinState* GameWinState::s_pInstance = NULL;

void GameWinState::s_goToMain()
{
	Game::Instance()->getStateMachine()->changeState(MenuState::Instance());
}

void GameWinState::s_resumePlay()
{
	Game::Instance()->getStateMachine()->popState();
}

void GameWinState::update()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}

void GameWinState::render()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}


bool GameWinState::onEnter()
{
	if (!TheTextureManager::Instance()->load("assets/resume.png",
		"resumebutton", Game::Instance()->getRenderer())) {
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/main.png",
		"mainbutton", Game::Instance()->getRenderer())) {
		return false;
	}
	if (!TheTextureManager::Instance()->load("Assets/Win.png",
		"Win", Game::Instance()->getRenderer())) {
		return false;
	}
	GameObject* WIn = new AnimatedGraphic(new
		LoaderParams(200, 0, 200, 80, "Win"),1);
	GameObject* button1 = new MenuButton(new
		LoaderParams(200, 100, 200, 80, "mainbutton"), s_goToMain);
	GameObject* button2 = new MenuButton(new
		LoaderParams(200, 300, 200, 80, "resumebutton"), s_resumePlay);
	m_gameObjects.push_back(WIn);
	m_gameObjects.push_back(button1);
	m_gameObjects.push_back(button2);
	std::cout << "entering PauseState\n";
	return true;
}

bool GameWinState::onExit()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();
	TheTextureManager::Instance()
		->clearFromTextureMap("resumebutton");
	TheTextureManager::Instance()
		->clearFromTextureMap("mainbutton");
	TheTextureManager::Instance()
		->clearFromTextureMap("Win");
	// reset the mouse button states to false
	TheInputHandler::Instance()->reset();
	std::cout << "exiting PauseState\n";
	return true;
}

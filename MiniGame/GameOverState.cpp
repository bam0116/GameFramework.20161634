#include "GameOverState.h"


const std::string GameOverState::s_gameOverID = "GAMEOVER";
GameOverState* GameOverState::s_pInstance = NULL;


void GameOverState::s_gameOverToMain()
{
	Game::Instance()->getStateMachine()->changeState(MenuState::Instance());
}
void GameOverState::s_restartPlay()
{
	Game::Instance()->getStateMachine()->changeState(PlayState::Instance());
}
void GameOverState::render()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}
void GameOverState::update()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}



bool GameOverState::onEnter()
{
	if (!TheTextureManager::Instance()->load("Assets/gameover.png",
		"gameovertext", Game::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("Assets/main.png",
		"mainbutton", Game::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("Assets/restart.png",
		"restartbutton", Game::Instance()->getRenderer()))
	{
		return false;
	}

	GameObject* gameOverText = new AnimatedGraphic(
		new  LoaderParams(200, 100, 190, 30, "gameovertext"), 2);

	GameObject* button1 = new MenuButton(
		new LoaderParams(200, 200, 200, 80, "mainbutton"),
		s_gameOverToMain);

	GameObject* button2 = new MenuButton(
		new LoaderParams(200, 300, 200, 80, "restartbutton"),
		s_restartPlay);

	m_gameObjects.push_back(gameOverText);
	m_gameObjects.push_back(button1);
	m_gameObjects.push_back(button2);
	std::cout << "entering PauseState\n";
	return true;
}

bool GameOverState::onExit()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();
	return true;
}
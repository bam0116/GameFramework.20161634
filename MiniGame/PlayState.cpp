#include "PlayState.h"

const std::string PlayState::s_playID = "PLAY";
PlayState* PlayState::s_pInstance = NULL;

Uint32 TimerStartTime, TimercurrentTime;
const float StopTime = 20000.0f;

void PlayState::update()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
	for (int i = 0; i < m_bullet.size(); i++)
	{
		m_bullet[i]->update(); 
		if (checkCollision(
			dynamic_cast<SDLGameObject*>(m_gameObjects[1]),
			dynamic_cast<SDLGameObject*>(m_bullet[i])))
		{
			Game::Instance()->getStateMachine()->changeState(GameOverState::Instance());
		}
	}

	TimerStartTime = SDL_GetTicks();

	if (StopTime <= TimerStartTime - TimercurrentTime)
	{
		Game::Instance()->getStateMachine()->changeState(GameWinState::Instance());
		TimercurrentTime = SDL_GetTicks();
	}
	
	if (TheInputHandler::Instance()->isKeyDown(
		SDL_SCANCODE_ESCAPE))
	{
		Game::Instance()->getStateMachine()->changeState(PauseState::Instance());
	}
}

void PlayState::render()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
	for (int i = 0; i < m_bullet.size(); i++)
	{
		m_bullet[i]->draw();
	}
}

bool PlayState::onEnter()
{
	if (!TheTextureManager::Instance()->load("Assets/helicopter.png",
		"helicopter", Game::Instance()->getRenderer())) {
		return false;
	}
	if (!TheTextureManager::Instance()->load("Assets/helicopter2.png",
		"helicopter2", Game::Instance()->getRenderer())) {
		return false;
	}
	if (!TheTextureManager::Instance()->load("Assets/BG.jpg",
		"BG", Game::Instance()->getRenderer())) {
		return false;
	}
	if (!TheTextureManager::Instance()->load("Assets/bullet.png",
		"bullet", Game::Instance()->getRenderer())) {
		return false;
	}
	GameObject* BG = new MoveBg(
		new LoaderParams(-70, 0, 709, 1169, "BG"));
	GameObject* player = new Player(
		new LoaderParams(250, 420, 128, 55, "helicopter"));
	GameObject* enemy = new Enemy(
		new LoaderParams(100, 0, 128, 55, "helicopter2"));
	m_gameObjects.push_back(BG);
	m_gameObjects.push_back(player);
	m_gameObjects.push_back(enemy);
	std::cout << "entering PlayState\n";
	return true;

}

bool PlayState::checkCollision(SDLGameObject* p1, SDLGameObject* p2)
{
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	leftA = p1->getPosition().getX();
	rightA = p1->getPosition().getX() + p1->getWidth();
	topA = p1->getPosition().getY();
	bottomA = p1->getPosition().getY() + p1->getHeight();

	//Calculate the sides of rect B
	leftB = p2->getPosition().getX();
	rightB = p2->getPosition().getX() + p2->getWidth();
	topB = p2->getPosition().getY();
	bottomB = p2->getPosition().getY() + p2->getHeight();

	//If any of the sides from A are outside of B
	if (bottomA <= topB) { return false; }
	if (topA >= bottomB) { return false; }
	if (rightA <= leftB) { return false; }
	if (leftA >= rightB) { return false; }
	return true;
}


bool PlayState::onExit()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}
	for (int i = 0; i < m_bullet.size(); i++)
	{
		m_bullet[i]->clean();
	}
	m_gameObjects.clear();
	m_bullet.clear();
	TheTextureManager::Instance()->clearFromTextureMap("BG");
	TheTextureManager::Instance()->clearFromTextureMap("helicopter");
	TheTextureManager::Instance()->clearFromTextureMap("helicopter2");
	TheTextureManager::Instance()->clearFromTextureMap("bullet");
	std::cout << "exiting PlayState\n";
	return true;
}
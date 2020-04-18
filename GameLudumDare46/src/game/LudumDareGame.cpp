#include "LudumDareGame.h"

bool LudumDareGame::init()
{
	bool isEngineInit = Engine::getInstance()->init();

	if (!isEngineInit)
	{
		return false;
	}

	SceneManager::getInstance()->setInitialScene(new MenuScene());

	return true;
}

void LudumDareGame::events()
{
	Engine::getInstance()->events();
}

void LudumDareGame::update(float delta)
{
	Engine::getInstance()->update(delta);

	SceneManager::getInstance()->getCurrentScene()->update(delta);

	Camera::getInstance()->update();
}

void LudumDareGame::draw()
{
	Engine::getInstance()->drawStart();

	SceneManager::getInstance()->getCurrentScene()->draw();

	Engine::getInstance()->drawEnd();
}

void LudumDareGame::dispose()
{
	SceneManager::getInstance()->getCurrentScene()->dispose();

	Engine::getInstance()->dispose();
}

bool LudumDareGame::isRunning()
{
	return Engine::getInstance()->isRunning();
}

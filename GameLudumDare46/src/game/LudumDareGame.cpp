#include "LudumDareGame.h"

bool LudumDareGame::init()
{
	bool isEngineInit = Engine::getInstance()->init();

	if (!isEngineInit)
	{
		return false;
	}

	//this->currentScene = new

	TextureManager::getInstance()->load("test", "assets/test.png");

	return true;
}

void LudumDareGame::events()
{
	Engine::getInstance()->events();
}

void LudumDareGame::update(float delta)
{
	Engine::getInstance()->update(delta);

	//this->currentScene->update(delta);

	Camera::getInstance()->update(delta);
}

void LudumDareGame::draw()
{
	Engine::getInstance()->drawStart();

	//this->currentScene->draw();

	int w, h;
	TextureManager::getInstance()->queryWidthAndHeight("test", &w, &h);
	TextureManager::getInstance()->render("test", 100, 100, w, h, w, h);

	Engine::getInstance()->drawEnd();
}

void LudumDareGame::dispose()
{
	//this->currentScene->dispose();

	Engine::getInstance()->dispose();
}

bool LudumDareGame::isRunning()
{
	return Engine::getInstance()->isRunning();
}

void LudumDareGame::changeScene(BaseScene* newScene)
{
	BaseScene* previousScene = this->currentScene;

	this->currentScene = newScene;

	previousScene->dispose();
}

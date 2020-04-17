#pragma once

#include "../core/Engine.h"
#include "../scenes/BaseScene.h"
#include "../graphics/Camera.h"
#include "../graphics/TextureManager.h"

class LudumDareGame
{
	BaseScene* currentScene;

public:

	bool init();
	void events();
	void update(float delta);
	void draw();
	void dispose();
	
	bool isRunning();

	void changeScene(BaseScene* newScene);
};

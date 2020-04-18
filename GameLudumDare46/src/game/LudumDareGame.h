#pragma once

#include "../core/Engine.h"
#include "../scenes/SceneManager.h"
#include "../graphics/Camera.h"
#include "../graphics/TextureManager.h"
#include "scenes/MenuScene.h"

class LudumDareGame
{
public:

	bool init();
	void events();
	void update(float delta);
	void draw();
	void dispose();
	
	bool isRunning();
};

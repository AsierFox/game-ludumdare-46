#pragma once

#include <spdlog/spdlog.h>

#include "../../scenes/BaseScene.h"
#include "../../scenes/BaseMenuScene.h"
#include "../../ui/Button.h"
#include "../../graphics/SpriteSheetRegion.h"
#include "../../scenes/SceneManager.h"
#include "ForestScene1.h"

class MenuScene : public BaseMenuScene
{
public:

	MenuScene();

	virtual void update(float delta) override;
	virtual void draw() override;
	virtual void dispose() override;

	static void onCickPlay();
	static void onCickCredits();
};

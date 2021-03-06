#pragma once

#include "../../scenes/BaseMenuScene.h"
#include "../../ui/Button.h"
#include "../../graphics/SpriteSheetRegion.h"
#include "../../scenes/SceneManager.h"
#include "IntroScene.h"
#include "CreditScene.h"

class MenuScene : public BaseMenuScene
{
	Font* title;

public:

	MenuScene();

	virtual void update(float delta) override;
	virtual void draw() override;
	virtual void dispose() override;

	static void onClickPlay();
	static void onClickCredits();
};

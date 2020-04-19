#pragma once

#include "../../scenes/BaseMenuScene.h"
#include "../../ui/Button.h"
#include "../../graphics/SpriteSheetRegion.h"
#include "../../scenes/SceneManager.h"
#include "../../media/Font.h"
#include "ForestScene1.h"

class IntroScene : public BaseMenuScene
{
	std::vector<Font*> m_fonts;

public:

	IntroScene();

	virtual void update(float delta) override;
	virtual void draw() override;
	virtual void dispose() override;

	static void onClickPlay();
	static void onClickBack();
};

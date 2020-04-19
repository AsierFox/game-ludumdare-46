#pragma once

#include <spdlog/spdlog.h>

#include "../../scenes/BaseMenuScene.h"
#include "../../ui/Button.h"
#include "../../graphics/SpriteSheetRegion.h"
#include "../../scenes/SceneManager.h"
#include "../../media/Font.h"
#include "MenuScene.h"

class CreditScene : public BaseMenuScene
{
	Font* m_gameTitle;

	std::vector<Font*> m_fonts;

public:

	CreditScene();

	virtual void update(float delta) override;
	virtual void draw() override;
	virtual void dispose() override;

	static void onClickBack();
};

#include "MenuScene.h"

MenuScene::MenuScene()
{
	float buttonsScale = 5;
	int buttonsMarginLeft = 380;
	int buttonsInitialMarginTop = 250;
	int buttonsMargin = 130;

	SpriteSheetRegion* playButtonNormalSprite = new SpriteSheetRegion("menu-play-button", "assets/sprites/ui.png", 1, 1, 10, 3, buttonsScale);
	SpriteSheetRegion* playButtonHoverSprite = new SpriteSheetRegion("menu-play-hover-button", "assets/sprites/ui.png", 2, 1, 10, 3, buttonsScale);
	Button* playButton = new Button(buttonsMarginLeft, buttonsInitialMarginTop, MenuScene::onCickPlay, playButtonNormalSprite, playButtonHoverSprite);
	this->m_uiComponents.push_back(playButton);

	SpriteSheetRegion* creditsButtonNormalSprite = new SpriteSheetRegion("menu-credits-button", "assets/sprites/ui.png", 1, 2, 10, 3, buttonsScale);
	SpriteSheetRegion* creditsButtonHoverSprite = new SpriteSheetRegion("menu-credits-hover-button", "assets/sprites/ui.png", 2, 2, 10, 3, buttonsScale);
	Button* creditsButton = new Button(buttonsMarginLeft, buttonsInitialMarginTop + buttonsMargin, []() { spdlog::debug("MEW"); }, creditsButtonNormalSprite, creditsButtonHoverSprite);
	this->m_uiComponents.push_back(creditsButton);
}

void MenuScene::update(float delta)
{
	for (BaseUI* ui : this->m_uiComponents)
	{
		ui->update();
	}
}

void MenuScene::draw()
{
	for (BaseUI* ui : this->m_uiComponents)
	{
		ui->draw();
	}
}

void MenuScene::dispose()
{
	for (BaseUI* ui : this->m_uiComponents)
	{
		//ui->dispose();
	}
}

void MenuScene::onCickPlay()
{
	SceneManager::getInstance()->switchScene(new ForestScene1());
}

void MenuScene::onCickCredits()
{
	spdlog::debug("MEW Credits");
}

#include "MenuScene.h"

MenuScene::MenuScene()
{
	float buttonsScale = 5;
	int buttonsMarginLeft = 380;
	int buttonsInitialMarginTop = 350;
	int buttonsMargin = 130;

	SpriteSheetRegion* playButtonNormalSprite = new SpriteSheetRegion("menu-play-button", "assets/sprites/ui.png", 1, 1, 10, 3, buttonsScale);
	SpriteSheetRegion* playButtonHoverSprite = new SpriteSheetRegion("menu-play-hover-button", "assets/sprites/ui.png", 2, 1, 10, 3, buttonsScale);
	Button* playButton = new Button(buttonsMarginLeft, buttonsInitialMarginTop, MenuScene::onClickPlay, playButtonNormalSprite, playButtonHoverSprite);
	this->m_uiComponents.push_back(playButton);

	SpriteSheetRegion* creditsButtonNormalSprite = new SpriteSheetRegion("menu-credits-button", "assets/sprites/ui.png", 1, 2, 10, 3, buttonsScale);
	SpriteSheetRegion* creditsButtonHoverSprite = new SpriteSheetRegion("menu-credits-hover-button", "assets/sprites/ui.png", 2, 2, 10, 3, buttonsScale);
	Button* creditsButton = new Button(buttonsMarginLeft, buttonsInitialMarginTop + buttonsMargin, MenuScene::onClickCredits, creditsButtonNormalSprite, creditsButtonHoverSprite);
	this->m_uiComponents.push_back(creditsButton);

	this->title = new Font("assets/font.ttf", "Be Cool or Die", 180);
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
	this->title->renderFont(50, 80);

	for (BaseUI* ui : this->m_uiComponents)
	{
		ui->draw();
	}
}

void MenuScene::dispose()
{
}

void MenuScene::onClickPlay()
{
	SceneManager::getInstance()->switchScene(new IntroScene());
}

void MenuScene::onClickCredits()
{
	SceneManager::getInstance()->switchScene(new CreditScene());
}

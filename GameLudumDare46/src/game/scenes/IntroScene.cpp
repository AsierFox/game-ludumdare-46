#include "IntroScene.h"

IntroScene::IntroScene()
{
	float buttonsScale = 5;
	SpriteSheetRegion* playButtonNormalSprite = new SpriteSheetRegion("menu-play-button", "assets/sprites/ui.png", 1, 1, 10, 3, buttonsScale);
	SpriteSheetRegion* playButtonHoverSprite = new SpriteSheetRegion("menu-play-hover-button", "assets/sprites/ui.png", 2, 1, 10, 3, buttonsScale);
	Button* playButton = new Button(600, 350, IntroScene::onClickPlay, playButtonNormalSprite, playButtonHoverSprite);
	this->m_uiComponents.push_back(playButton);

	SpriteSheetRegion* backButtonNormalSprite = new SpriteSheetRegion("menu-play-button", "assets/sprites/ui.png", 3, 1, 10, 3, buttonsScale);
	SpriteSheetRegion* backButtonHoverSprite = new SpriteSheetRegion("menu-play-hover-button", "assets/sprites/ui.png", 4, 1, 10, 3, buttonsScale);
	Button* backButton = new Button(600, 450, IntroScene::onClickBack, backButtonNormalSprite, backButtonHoverSprite);
	this->m_uiComponents.push_back(backButton);

	float fontSize = 28;
	this->m_fonts.push_back(new Font("assets/font.ttf", "One day, a cool teenager was trying filtering with his crush. This pretty girl liked a lot", fontSize));
	this->m_fonts.push_back(new Font("assets/font.ttf", "wild animals. So our cool guy decided to go to the forest to take some photos of this animals.", fontSize));
	this->m_fonts.push_back(new Font("assets/font.ttf", "Go! And take as much photos as you can of the wild animals! :)", fontSize));
}

void IntroScene::update(float delta)
{
	for (BaseUI* ui : this->m_uiComponents)
	{
		ui->update();
	}
}

void IntroScene::draw()
{

	for (BaseUI* ui : this->m_uiComponents)
	{
		ui->draw();
	}

	int initialTop = 180;

	for (Font* font : this->m_fonts)
	{
		font->renderFont(50, initialTop);

		initialTop += 30;
	}
}

void IntroScene::dispose()
{
	for (Font* font : this->m_fonts)
	{
		font->dispose();
	}
}

void IntroScene::onClickPlay()
{
	SceneManager::getInstance()->switchScene(new ForestScene1());
}

void IntroScene::onClickBack()
{
	SceneManager::getInstance()->switchScene(new MenuScene());
}

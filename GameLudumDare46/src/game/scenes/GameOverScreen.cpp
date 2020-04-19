#include "GameOverScreen.h"

GameOverScreen::GameOverScreen(GameObjectType diedType)
{
	float buttonsScale = 5;
	SpriteSheetRegion* backButtonNormalSprite = new SpriteSheetRegion("game-over-menu-button", "assets/sprites/ui.png", 3, 1, 10, 3, buttonsScale);
	SpriteSheetRegion* backButtonHoverSprite = new SpriteSheetRegion("game-over-menu-button", "assets/sprites/ui.png", 4, 1, 10, 3, buttonsScale);
	Button* backButton = new Button(600, 450, GameOverScreen::onClickBack, backButtonNormalSprite, backButtonHoverSprite);
	this->m_uiComponents.push_back(backButton);

	this->m_gameTitle = new Font("assets/font.ttf", "Be Cool or Die", 180);

	float fontSize = 28;

	if (GameObjectType::AGGRESSIVE_ANIMAL == diedType)
	{
		this->m_fonts.push_back(new Font("assets/font.ttf", "The cool guy was ATTACKED by a bear!!! He has never been in the forest...", fontSize));
		this->m_fonts.push_back(new Font("assets/font.ttf", "He understimate the power of the nature!! :((", fontSize));
		this->m_fonts.push_back(new Font("assets/font.ttf", "Get hooked up with your crush has never been easy :/", fontSize));
	}
	else
	{
		this->m_fonts.push_back(new Font("assets/font.ttf", "The cool guy was runned out of battery!!! So he just worried to much that he was not", fontSize));
		this->m_fonts.push_back(new Font("assets/font.ttf", "able to continue, he has no photos for her crush!!!!!! :(((((", fontSize));
	}
}

void GameOverScreen::update(float delta)
{
	for (BaseUI* ui : this->m_uiComponents)
	{
		ui->update();
	}
}

void GameOverScreen::draw()
{
	this->m_gameTitle->renderFont(50, 80);

	for (BaseUI* ui : this->m_uiComponents)
	{
		ui->draw();
	}

	int initialTop = 280;

	for (Font* font : this->m_fonts)
	{
		font->renderFont(50, initialTop);

		initialTop += 30;
	}
}

void GameOverScreen::dispose()
{
	for (Font* font : this->m_fonts)
	{
		font->dispose();
	}
}

void GameOverScreen::onClickBack()
{
	SceneManager::getInstance()->switchScene(new MenuScene());
}

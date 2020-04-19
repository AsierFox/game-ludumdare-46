#include "CreditScene.h"

CreditScene::CreditScene()
{
	float buttonsScale = 5;
	SpriteSheetRegion* backButtonNormalSprite = new SpriteSheetRegion("menu-play-button", "assets/sprites/ui.png", 3, 1, 10, 3, buttonsScale);
	SpriteSheetRegion* backButtonHoverSprite = new SpriteSheetRegion("menu-play-hover-button", "assets/sprites/ui.png", 4, 1, 10, 3, buttonsScale);
	Button* backButton = new Button(600, 450, CreditScene::onClickBack, backButtonNormalSprite, backButtonHoverSprite);
	this->m_uiComponents.push_back(backButton);

	this->m_gameTitle = new Font("assets/font.ttf", "Be Cool or Die", 180);

	float fontSize = 28;
	this->m_fonts.push_back(new Font("assets/font.ttf", "This is my first Ludum Dare game! I learned lots of things during the development and", fontSize));
	this->m_fonts.push_back(new Font("assets/font.ttf", "it has motivated me a lot!! I developed this game using my own game engine done in SDL2", fontSize));
	this->m_fonts.push_back(new Font("assets/font.ttf", "and I'm so proud of it :)", fontSize));
	this->m_fonts.push_back(new Font("assets/font.ttf", "I hope that with the experience achived here I can improve my own skills of developmnet", fontSize));
	this->m_fonts.push_back(new Font("assets/font.ttf", "and design!! Thank you so much for playing my game and see you in the next LD!! :D", fontSize));
}

void CreditScene::update(float delta)
{
	for (BaseUI* ui : this->m_uiComponents)
	{
		ui->update();
	}
}

void CreditScene::draw()
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

void CreditScene::dispose()
{
	for (Font* font : this->m_fonts)
	{
		font->dispose();
	}
}

void CreditScene::onClickBack()
{
	SceneManager::getInstance()->switchScene(new MenuScene());
}

#include "BatteryLifeUI.h"

BatteryLifeUI::BatteryLifeUI()
	: BaseUI()
{
	float scale = 5;

	this->m_pos = Vector2D(10, 30);
	this->m_sprite = new SpriteSheetRegion("battery-life-hud", "assets/sprites/ui.png", 2, 3, 10, 3, scale);

	this->m_informativeFont = new Font("assets/font.ttf", "Ok, this is easy! Lets go to take some photos!", 24);
	this->m_informativeFont1 = new Font("assets/font.ttf", "Oh noo!! My battery is wasting!!", 24);
	this->m_informativeFont2 = new Font("assets/font.ttf", "I will not be able to turn on my crush T-T", 24);

	this->m_everySecondsLost = 3000;
	this->m_timerStart = SDL_GetTicks();

	this->m_isBatteSpent = false;
}

void BatteryLifeUI::update()
{
	this->m_timer = SDL_GetTicks() - this->m_timerStart;

	if (this->m_timer >= this->m_everySecondsLost)
	{
		this->resetTimer();

		this->lostBattery();
	}
}

void BatteryLifeUI::draw()
{
	this->m_sprite->renderFixed(this->m_pos.x, this->m_pos.y);

	if (this->m_sprite->getCol() == 2)
	{
		this->m_informativeFont->renderFont(300, 180);
	}
	else if (this->m_sprite->getCol() == 5)
	{
		this->m_informativeFont1->renderFont(300, 180);
	}
	else if (this->m_sprite->getCol() == 7)
	{
		this->m_informativeFont2->renderFont(300, 180);
	}
}

void BatteryLifeUI::dispose()
{
}

void BatteryLifeUI::achievedBattery()
{
	if (1 == this->m_sprite->getCol())
	{
		return;
	}

	this->resetTimer();

	this->m_sprite->updateCol(this->m_sprite->getCol() - 1);
}

void BatteryLifeUI::lostBattery()
{
	this->m_isBatteSpent = this->m_sprite->getCol() == 10;

	if (10 == this->m_sprite->getCol())
	{
		return;
	}

	this->m_sprite->updateCol(this->m_sprite->getCol() + 1);
}

bool BatteryLifeUI::isBatterySpent()
{
	return this->m_isBatteSpent;
}

void BatteryLifeUI::resetTimer()
{
	this->m_timerStart = SDL_GetTicks();
}

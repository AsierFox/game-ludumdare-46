#pragma once

#include "../../ui/BaseUI.h"
#include "../../graphics/SpriteSheetRegion.h"
#include "../../scenes/SceneManager.h"
#include "../../media/Font.h"

class BatteryLifeUI : public BaseUI
{
	SpriteSheetRegion* m_sprite;

	int m_everySecondsLost;
	Uint32 m_timerStart;
	float m_timer;
	bool m_isBatteSpent;

	Font* m_informativeFont;
	Font* m_informativeFont1;
	Font* m_informativeFont2;

public:

	BatteryLifeUI();

	virtual void update() override;
	virtual void draw() override;
	virtual void dispose() override;

	void achievedBattery();
	void lostBattery();
	bool isBatterySpent();

private:

	void resetTimer();
};

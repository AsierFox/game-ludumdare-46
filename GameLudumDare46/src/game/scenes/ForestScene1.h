#pragma once

#include "../../scenes/BaseLevelScene.h"
#include "../entities/Player.h"
#include "../../tiledmap/TiledMapManager.h"
#include "../../entities/GameObjectFactory.h"
#include "../ui/BatteryLifeUI.h"
#include "GameOverScreen.h"

class ForestScene1 : public BaseLevelScene
{
	Player* m_player;
	BatteryLifeUI* m_batteryLifeHUD;

public:

	ForestScene1();

	virtual void update(float delta) override;
	virtual void draw() override;
	virtual void dispose() override;
};

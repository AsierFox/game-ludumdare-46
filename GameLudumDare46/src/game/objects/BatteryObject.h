#pragma once

#include "../../entities/GameObject.h"
#include "../../graphics/SpriteAnimation.h"

class BatteryObject : public GameObject
{
	SpriteAnimation* m_currentAnimation;

public:

	BatteryObject(std::string id, std::string name, int x, int y, TiledMap* map, SpriteAnimation* animation);

	virtual void setCollidernRegion() override;
	virtual void update(float delta) override;
	virtual void draw() override;
	virtual void dispose() override;
};

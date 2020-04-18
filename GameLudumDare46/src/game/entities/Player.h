#pragma once

#include <string>

#include "../../entities/Entity.h"
#include "../../tiledmap/TiledMap.h"

class Player : public Entity
{
	SpriteAnimation* m_idleAnimation;
	SpriteAnimation* m_rightWalkAnimation;

public:

	Player(std::string id, std::string name, int x, int y, TiledMap* map);

	virtual void setCollidernRegion() override;
	virtual void update(float delta) override;
	virtual void draw() override;
	virtual void dispose() override;
};

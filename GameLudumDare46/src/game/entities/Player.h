#pragma once

#include <string>

#include "../../entities/Entity.h"
#include "../../tiledmap/TiledMap.h"
#include "../../physics/CollisionHandler.h"

class Player : public Entity
{
	SpriteAnimation* m_idleAnimation;
	SpriteAnimation* m_rightWalkAnimation;

	Direction m_currentSpriteDirection;

	bool m_isDied;

public:

	Player(std::string id, std::string name, int x, int y, TiledMap* map);

	virtual void setColliderRegion() override;
	virtual void update(float delta) override;
	virtual void draw() override;
	virtual void dispose() override;
	virtual void interact(GameObject* other) override;
	virtual void proximityInteract(GameObject* other) override;

	void isDied(bool isDied);
	bool isDied();
};

#pragma once

#include <string>

#include "../entities/Animal.h"
#include "../../graphics/SpriteAnimation.h"
#include "../../ai/AStarFinding.h"
#include "../entities/Player.h"

class AggressiveAnimal : public Animal
{
	SpriteAnimation* m_idleAnimation;
	SpriteAnimation* m_moveAnimation;

	AStarFinding* m_aStar;
	Vector2D m_nextFindingCell;

public:

	AggressiveAnimal(std::string id, std::string name, int x, int y, TiledMap* map, SpriteAnimation* idleAnimation, SpriteAnimation* moveAnimation);

	virtual void setColliderRegion() override;
	virtual void update(float delta) override;
	virtual void draw() override;
	virtual void dispose() override;
	virtual void interact(GameObject* other) override;
	virtual void proximityInteract(GameObject* other) override;
};

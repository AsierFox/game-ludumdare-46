#pragma once

#include "Animal.h"
#include "../../types/Direction.h"

class RegularAnimal : public Animal
{
	SpriteAnimation* m_idleAnimation;
	SpriteAnimation* m_moveAnimation;

	Direction m_currentSpriteDirection;

public:

	RegularAnimal(std::string id, std::string name, int x, int y, TiledMap* map, SpriteAnimation* idleAnimation, SpriteAnimation* moveAnimation);

	virtual void setColliderRegion() override;
	virtual void update(float delta) override;
	virtual void draw() override;
	virtual void dispose() override;
	virtual void interact(GameObject* other) override;
	virtual void proximityInteract(GameObject* other) override;
};

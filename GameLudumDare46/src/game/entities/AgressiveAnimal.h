#pragma once

#include <string>

#include "../entities/Animal.h"
#include "../../graphics/SpriteAnimation.h"

class AgressiveAnimal : public Animal
{
	SpriteAnimation* m_idleAnimation;
	SpriteAnimation* m_moveAnimation;

public:

	AgressiveAnimal(std::string id, std::string name, int x, int y, TiledMap* map, SpriteAnimation* idleAnimation, SpriteAnimation* moveAnimation);

	virtual void setCollidernRegion() override;
	virtual void update(float delta) override;
	virtual void draw() override;
	virtual void dispose() override;
};

#pragma once

#include "Animal.h"

class RegularAnimal : public Animal
{
	SpriteAnimation* m_idleAnimation;
	SpriteAnimation* m_moveAnimation;

public:

	RegularAnimal(std::string id, std::string name, int x, int y, TiledMap* map, SpriteAnimation* idleAnimation, SpriteAnimation* moveAnimation);

	virtual void setCollidernRegion() override;
	virtual void update(float delta) override;
	virtual void draw() override;
	virtual void dispose() override;
};

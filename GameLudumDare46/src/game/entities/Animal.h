#pragma once

#include "../../entities/Entity.h"
#include "../../graphics/SpriteAnimation.h"

class Animal : public Entity
{
public:

	Animal(std::string id, std::string name, int x, int y, TiledMap* map);

	virtual void setColliderRegion() = 0;
	virtual void update(float delta) = 0;
	virtual void draw() = 0;
	virtual void dispose() = 0;
	virtual void interact(GameObject* other) = 0;
	virtual void proximityInteract(GameObject* other) = 0;
};

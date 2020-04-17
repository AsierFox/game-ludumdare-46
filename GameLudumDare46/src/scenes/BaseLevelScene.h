#pragma once

#include <vector>

#include "BaseScene.h"
#include "../physics/Vector2D.h"
#include "../tiledmap/TiledMap.h"
#include "../entities/Entity.h"

class BaseLevelScene : public BaseScene
{
protected:

	std::vector<Entity*> m_entities;

	TiledMap* m_map;

public:

	virtual void update(float delta) = 0;
	virtual void draw() = 0;
	virtual void dispose() = 0;

	TiledMap* getMap();
};

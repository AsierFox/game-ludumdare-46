#pragma once

#include "../entities/Entity.h"
#include "../game/entities/RegularAnimal.h"
#include "../game/entities/AgressiveAnimal.h"
#include "../game/objects/BatteryObject.h"

enum struct EntityType : short int
{
	BIRD = 0,
	SQUIRREL = 1,
	RABBIT = 2,
	FOX = 3,
	BEAR = 4
};

enum struct ObjectType : short int
{
	BATTERY = 0
};

class GameObjectFactory
{
	static GameObjectFactory* s_instance;

	unsigned int nextEnemyId;

	GameObjectFactory();

public:

	static GameObjectFactory* getInstance();

	Entity* createEntity(int x, int y, EntityType entityType, TiledMap* belongsToMap);
	GameObject* createMapObject(int x, int y, ObjectType type, TiledMap* belongsToMap);
};

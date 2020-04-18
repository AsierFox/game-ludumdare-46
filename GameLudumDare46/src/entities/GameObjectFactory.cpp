#include "GameObjectFactory.h"

GameObjectFactory* GameObjectFactory::s_instance = nullptr;

GameObjectFactory::GameObjectFactory()
{
	this->nextEnemyId = 1;
}

GameObjectFactory* GameObjectFactory::getInstance()
{
	if (nullptr == GameObjectFactory::s_instance)
	{
		GameObjectFactory::s_instance = new GameObjectFactory();
	}

	return GameObjectFactory::s_instance;
}

Entity* GameObjectFactory::createEntity(int x, int y, EntityType type, TiledMap* belongsToMap)
{
	Entity* entity = nullptr;
	std::string entityId = "regular-animal-" + this->nextEnemyId;

	switch (type)
	{
	case EntityType::BIRD:
		entity = new RegularAnimal(entityId, "bird", x, y, belongsToMap,
			new SpriteAnimation(entityId + "-idle", "assets/sprites/animals.png", 1, 2, 2, 4, 3),
			new SpriteAnimation(entityId + "-move", "assets/sprites/animals.png", 1, 2, 2, 4, 3));
		break;
	
	case EntityType::SQUIRREL:
		entity = new RegularAnimal(entityId, "squirrel", x, y, belongsToMap,
			new SpriteAnimation(entityId + "-idle", "assets/sprites/animals.png", 2, 2, 2, 4, 4),
			new SpriteAnimation(entityId + "-move", "assets/sprites/animals.png", 2, 2, 2, 4, 4));
		break;
	
	case EntityType::RABBIT:
		entity = new RegularAnimal(entityId, "rabbit", x, y, belongsToMap,
			new SpriteAnimation(entityId + "-idle", "assets/sprites/animals.png", 3, 2, 2, 4, 5),
			new SpriteAnimation(entityId + "-move", "assets/sprites/animals.png", 3, 2, 2, 4, 5));
		break;

	case EntityType::FOX:
		entity = new RegularAnimal(entityId, "fox", x, y, belongsToMap,
			new SpriteAnimation(entityId + "-idle", "assets/sprites/animals.png", 4, 2, 2, 4, 6),
			new SpriteAnimation(entityId + "-move", "assets/sprites/animals.png", 4, 2, 2, 4, 6));
		break;

	case EntityType::BEAR:
		entity = new AgressiveAnimal(entityId, "bear", x, y, belongsToMap,
			new SpriteAnimation(entityId + "-idle", "assets/sprites/bear.png", 1, 1, 3, 1, 6),
			new SpriteAnimation(entityId + "-move", "assets/sprites/bear.png", 1, 1, 3, 1, 6));
		break;
	}

	if (nullptr == entity)
	{
		spdlog::critical("[GameObjectFactory::createRegularAnimal] Cannot create entity type '{0}'", type);
	}
	else
	{
		this->nextEnemyId++;
	}

	return entity;
}

GameObject* GameObjectFactory::createMapObject(int x, int y, ObjectType type, TiledMap* belongsToMap)
{
	GameObject* object = nullptr;
	std::string entityId = "game-object-" + this->nextEnemyId;

	switch (type)
	{
	case ObjectType::BATTERY:
		object = new BatteryObject(entityId, "battery", x, y, belongsToMap,
			new SpriteAnimation(entityId, "assets/sprites/objects.png", 1, 1, 2, 1, 3));
		break;
	}

	if (nullptr == object)
	{
		spdlog::critical("[GameObjectFactory::createMapObject] Cannot create object type '{0}'", type);
	}
	else
	{
		this->nextEnemyId++;
	}

	return object;
}

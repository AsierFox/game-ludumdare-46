#include "ForestScene1.h"

ForestScene1::ForestScene1()
{
	this->m_map = TiledMapManager::getInstance()->load("forest-level-1", "assets/sprites/", "map.json", 8);

	// Load entities & object of the map
	for (MapSpawnPoint mapSpawnPoint : this->m_map->getSpawns())
	{
		for (MapSpawnProperty mapSpawnProperty : mapSpawnPoint.properties)
		{
			if ("object" == mapSpawnProperty.type)
			{
				if ("battery" == mapSpawnProperty.value)
				{
					m_objects.push_back(GameObjectFactory::getInstance()->createMapObject(mapSpawnPoint.point.x, mapSpawnPoint.point.y, ObjectType::BATTERY, this->m_map));
				}
			}
			else if ("animal" == mapSpawnProperty.type)
			{
				if ("bird" == mapSpawnProperty.value)
				{
					this->m_entities.push_back(GameObjectFactory::getInstance()->createEntity(mapSpawnPoint.point.x, mapSpawnPoint.point.y, EntityType::BIRD, this->m_map));
				}
				else if ("squirrel" == mapSpawnProperty.value)
				{
					this->m_entities.push_back(GameObjectFactory::getInstance()->createEntity(mapSpawnPoint.point.x, mapSpawnPoint.point.y, EntityType::SQUIRREL, this->m_map));
				}
				else if ("rabbit" == mapSpawnProperty.value)
				{
					this->m_entities.push_back(GameObjectFactory::getInstance()->createEntity(mapSpawnPoint.point.x, mapSpawnPoint.point.y, EntityType::RABBIT, this->m_map));
				}
				else if ("fox" == mapSpawnProperty.value)
				{
					this->m_entities.push_back(GameObjectFactory::getInstance()->createEntity(mapSpawnPoint.point.x, mapSpawnPoint.point.y, EntityType::FOX, this->m_map));
				}
				else if ("bear" == mapSpawnProperty.value)
				{
					this->m_entities.push_back(GameObjectFactory::getInstance()->createEntity(mapSpawnPoint.point.x, mapSpawnPoint.point.y, EntityType::BEAR, this->m_map));
				}
			}
		}
	}

	this->m_player = new Player("player", "player", 100, 100, this->m_map);
	this->m_batteryLifeHUD = new BatteryLifeUI();

	Camera::getInstance()->updateTarget(this->m_player->getOrigin());
	Camera::getInstance()->setSceneMapDimensions(this->m_map->getTotalWidth(), this->m_map->getTotalHeight());
}

void ForestScene1::update(float delta)
{
	this->m_map->update();

	for (GameObject* object : this->m_objects)
	{
		if (!object->isDisabled())
		{
			object->update(delta);
		}
	}

	for (Entity* entity : this->m_entities)
	{
		if (!entity->isDisabled())
		{
			entity->update(delta);
		}
	}

	this->m_player->update(delta);

	this->m_batteryLifeHUD->update();

	// Check interactions with player
	for (Entity* entity : this->m_entities)
	{
		if (entity->isDisabled())
		{
			continue;
		}

		if (MathUtils::isInRadius(this->m_player->getOrigin(), entity->getOrigin(), 400))
		{
			this->m_player->proximityInteract(entity);
			entity->proximityInteract(this->m_player);

			if (CollisionHandler::getInstance()->checkCollision(this->m_player->getCollider(), entity->getCollider()))
			{
				this->m_player->interact(entity);
				entity->interact(this->m_player);
			}
		}
	}

	for (GameObject* object : this->m_objects)
	{
		if (object->isDisabled())
		{
			continue;
		}

		if (MathUtils::isInRadius(this->m_player->getOrigin(), object->getOrigin(), 200))
		{
			if (CollisionHandler::getInstance()->checkCollision(this->m_player->getCollider(), object->getCollider()))
			{
				if (GameObjectType::BATTERY == object->getType())
				{
					this->m_batteryLifeHUD->achievedBattery();
				}

				this->m_player->interact(object);
				object->interact(this->m_player);
			}
		}
	}

	// Check game status
	if (this->m_player->isDied())
	{
		SceneManager::getInstance()->setInitialScene(new GameOverScreen(GameObjectType::AGGRESSIVE_ANIMAL));
	}
	else if (this->m_batteryLifeHUD->isBatterySpent())
	{
		SceneManager::getInstance()->setInitialScene(new GameOverScreen(GameObjectType::BATTERY));
	}
}

void ForestScene1::draw()
{
	this->m_map->render();

	for (GameObject* object : this->m_objects)
	{
		if (!object->isDisabled())
		{
			object->draw();
		}
	}

	for (Entity* entity : this->m_entities)
	{
		if (!entity->isDisabled())
		{
			entity->draw();
		}
	}

	this->m_player->draw();

	this->m_batteryLifeHUD->draw();
}

void ForestScene1::dispose()
{
	// TODO Dispose objects & entities
	this->m_player->dispose();
	this->m_map->dispose();
}

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
			else if ("regular-animal" == mapSpawnProperty.type)
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
			}
		}
	}

	this->m_player = new Player("player", "player", 100, 100, this->m_map);

	Camera::getInstance()->updateTarget(this->m_player->getOrigin());
	Camera::getInstance()->setSceneMapDimensions(this->m_map->getTotalWidth(), this->m_map->getTotalHeight());
}

void ForestScene1::update(float delta)
{
	this->m_map->update();

	for (GameObject* object : this->m_objects)
	{
		object->update(delta);
	}

	for (Entity* entity : this->m_entities)
	{
		entity->update(delta);
	}

	this->m_player->update(delta);
}

void ForestScene1::draw()
{
	this->m_map->render();

	for (GameObject* object : this->m_objects)
	{
		object->draw();
	}

	for (Entity* entity : this->m_entities)
	{
		entity->draw();
	}

	this->m_player->draw();
}

void ForestScene1::dispose()
{
	// TODO Dispose objects & entities
	this->m_player->dispose();
	this->m_map->dispose();
}

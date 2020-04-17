#pragma once

class GameObjectFactory
{
	static GameObjectFactory* s_instance;

	unsigned int nextEnemyId;

	GameObjectFactory();

public:

	static GameObjectFactory* getInstance();

};

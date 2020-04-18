#include "Animal.h"

Animal::Animal(std::string id, std::string name, int x, int y, TiledMap* map)
	: Entity(id, name, x, y, map)
{
}

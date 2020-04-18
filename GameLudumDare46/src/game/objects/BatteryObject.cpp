#include "BatteryObject.h"

BatteryObject::BatteryObject(std::string id, std::string name, int x, int y, TiledMap* map, SpriteAnimation* animation)
	: GameObject(id, name, x, y, map)
{
	this->m_currentAnimation = animation;
}

void BatteryObject::setCollidernRegion()
{
}

void BatteryObject::update(float delta)
{
	this->m_currentAnimation->update();
}

void BatteryObject::draw()
{
	this->m_currentAnimation->render(this->m_transform->x , this->m_transform->y);
}

void BatteryObject::dispose()
{
}

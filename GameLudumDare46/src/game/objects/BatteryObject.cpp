#include "BatteryObject.h"

BatteryObject::BatteryObject(std::string id, std::string name, int x, int y, TiledMap* map, SpriteAnimation* animation)
	: GameObject(id, name, x, y, map)
{
	this->m_currentAnimation = animation;

	this->m_type = GameObjectType::BATTERY;

	this->setColliderRegion();
}

void BatteryObject::setColliderRegion()
{
	this->m_collider = {
		static_cast<int>(this->m_transform->x),
		static_cast<int>(this->m_transform->y),
		static_cast<int>(this->m_currentAnimation->getWidth()),
		static_cast<int>(this->m_currentAnimation->getHeight()) };

	this->m_origin->x = this->m_transform->x + (this->m_currentAnimation->getWidth() / 2);
	this->m_origin->y = this->m_transform->y + (this->m_currentAnimation->getHeight() / 2);
}

void BatteryObject::update(float delta)
{
	this->setColliderRegion();
	this->m_currentAnimation->update();
}

void BatteryObject::draw()
{
	this->m_currentAnimation->render(this->m_transform->x , this->m_transform->y);
}

void BatteryObject::dispose()
{
}

void BatteryObject::interact(GameObject* other)
{
	if (GameObjectType::PLAYER == other->getType())
	{
		this->m_isDisabled = true;
		this->m_wantsRemove = true;
	}
}

void BatteryObject::proximityInteract(GameObject* other)
{
}

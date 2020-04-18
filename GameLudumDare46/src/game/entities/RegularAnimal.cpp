#include "Animal.h"
#include "RegularAnimal.h"

RegularAnimal::RegularAnimal(std::string id, std::string name, int x, int y, TiledMap* map, SpriteAnimation* idleAnimation, SpriteAnimation* moveAnimation)
	: Animal(id, name, x, y, map)
{
	this->m_idleAnimation = idleAnimation;
	this->m_moveAnimation = moveAnimation;

	this->m_currentAnimation = this->m_idleAnimation;
}

void RegularAnimal::setCollidernRegion()
{
}

void RegularAnimal::update(float delta)
{
	this->m_origin->x = this->m_transform->x + (this->m_currentAnimation->getWidth() / 2);
	this->m_origin->y = this->m_transform->y + (this->m_currentAnimation->getHeight() / 2);

	this->m_currentAnimation->update();
}

void RegularAnimal::draw()
{
	this->m_currentAnimation->render(this->m_transform->x, this->m_transform->y);
}

void RegularAnimal::dispose()
{
}

#include "AgressiveAnimal.h"

AgressiveAnimal::AgressiveAnimal(std::string id, std::string name, int x, int y, TiledMap* map, SpriteAnimation* idleAnimation, SpriteAnimation* moveAnimation)
	: Animal(id, name, x, y, map)
{
	this->m_idleAnimation = idleAnimation;
	this->m_moveAnimation = moveAnimation;

	this->m_currentAnimation = idleAnimation;
}

void AgressiveAnimal::setCollidernRegion()
{
}

void AgressiveAnimal::update(float delta)
{
	this->m_currentAnimation->update();
}

void AgressiveAnimal::draw()
{
	this->m_currentAnimation->render(this->m_transform->x, this->m_transform->y);
}

void AgressiveAnimal::dispose()
{
}

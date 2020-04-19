#include "Animal.h"
#include "RegularAnimal.h"

RegularAnimal::RegularAnimal(std::string id, std::string name, int x, int y, TiledMap* map, SpriteAnimation* idleAnimation, SpriteAnimation* moveAnimation)
	: Animal(id, name, x, y, map)
{
	this->m_idleAnimation = idleAnimation;
	this->m_moveAnimation = moveAnimation;

	this->m_currentAnimation = this->m_idleAnimation;

	this->m_speed = 4;

	this->m_type = GameObjectType::REGULAR_ANIMAL;

	this->m_currentSpriteDirection = Direction::LEFT;

	this->setColliderRegion();
}

void RegularAnimal::setColliderRegion()
{
	this->m_collider = {
		static_cast<int>(this->m_transform->x),
		static_cast<int>(this->m_transform->y),
		static_cast<int>(this->m_currentAnimation->getWidth()),
		static_cast<int>(this->m_currentAnimation->getHeight()) };

	this->m_origin->x = this->m_transform->x + (this->m_currentAnimation->getWidth() / 2);
	this->m_origin->y = this->m_transform->y + (this->m_currentAnimation->getHeight() / 2);
}

void RegularAnimal::update(float delta)
{
	this->m_rigitBody->update(delta);
	this->m_transform->translateX(this->m_rigitBody->getNewPosition().x);
	this->m_transform->translateY(this->m_rigitBody->getNewPosition().y);

	this->setColliderRegion();

	// Update animation
	if (this->m_rigitBody->getForce().x > 0 && Direction::RIGHT != this->m_currentSpriteDirection)
	{
		this->m_currentAnimation->setFlip(SDL_FLIP_HORIZONTAL);

		this->m_currentSpriteDirection = Direction::RIGHT;
	}
	else if (this->m_rigitBody->getForce().x < 0 && Direction::LEFT != this->m_currentSpriteDirection)
	{
		this->m_currentAnimation->setFlip(SDL_FLIP_NONE);

		this->m_currentSpriteDirection = Direction::LEFT;
	}

	this->m_currentAnimation->update();
}

void RegularAnimal::draw()
{
	this->m_currentAnimation->render(this->m_transform->x, this->m_transform->y);
}

void RegularAnimal::dispose()
{
}

void RegularAnimal::interact(GameObject* other)
{
}

void RegularAnimal::proximityInteract(GameObject* other)
{
	if (GameObjectType::PLAYER == other->getType())
	{
		if (MathUtils::isInRadius(this->getOrigin(), other->getOrigin(), 180))
		{
			if (other->getOrigin()->x < this->m_origin->x)
			{
				this->m_rigitBody->setForceX(this->m_speed);
			}
			else
			{
				this->m_rigitBody->setForceX(-this->m_speed);
			}

			if (other->getOrigin()->y < this->m_origin->y)
			{
				this->m_rigitBody->setForceY(this->m_speed);
			}
			else
			{
				this->m_rigitBody->setForceY(-this->m_speed);
			}
		}
	}
}

#include "Player.h"

Player::Player(std::string id, std::string name, int x, int y, TiledMap* map)
	: Entity(id, name, x, y, map)
{
	float scale = 4;

	// Sprite animations
	this->m_idleAnimation = new SpriteAnimation("player-idle", "assets/sprites/player.png", 1, 3, 3, 3, scale);
	this->m_rightWalkAnimation = new SpriteAnimation("player-idle", "assets/sprites/player.png", 2, 1, 3, 3, scale);

	this->m_currentAnimation = this->m_idleAnimation;

	this->m_currentSpriteDirection = Direction::RIGHT;

	this->m_isDied = false;

	this->m_type = GameObjectType::PLAYER;
	this->m_speed = 4;

	this->setColliderRegion();
}

void Player::setColliderRegion()
{
	this->m_collider = {
		static_cast<int>(this->m_transform->x),
		static_cast<int>(this->m_transform->y),
		static_cast<int>(this->m_currentAnimation->getWidth()),
		static_cast<int>(this->m_currentAnimation->getHeight()) };

	this->m_origin->x = this->m_transform->x + (this->m_currentAnimation->getWidth() / 2);
	this->m_origin->y = this->m_transform->y + (this->m_currentAnimation->getHeight() / 2);
}

void Player::update(float delta)
{
	// Input process
	this->m_rigitBody->removeForce();

	if (InputHandler::getInstance()->isAxisKey(AxisDirection::UP))
	{
		this->m_rigitBody->setForceY(-this->m_speed);
	}
	else if (InputHandler::getInstance()->isAxisKey(AxisDirection::RIGHT))
	{
		this->m_rigitBody->setForceX(this->m_speed);
	}
	else if (InputHandler::getInstance()->isAxisKey(AxisDirection::LEFT))
	{
		this->m_rigitBody->setForceX(-this->m_speed);
	}
	else if (InputHandler::getInstance()->isAxisKey(AxisDirection::DOWN))
	{
		this->m_rigitBody->setForceY(this->m_speed);
	}

	this->m_rigitBody->update(delta);

	// Update colliders & check collisions
	this->m_lastSafePosition.x = this->m_transform->x;
	this->m_transform->translateX(this->m_rigitBody->getNewPosition().x);
	this->setColliderRegion();

	if (this->m_collider.x < 0 || this->m_collider.x + this->m_collider.w > this->belongsToMap->getTotalWidth())
	{
		this->m_transform->x = this->m_lastSafePosition.x;
	}
	else
	{
		for (SDL_Rect mapCollider : this->belongsToMap->getColliders())
		{
			if (CollisionHandler::getInstance()->checkCollision(this->m_collider, mapCollider))
			{
				this->m_transform->x = this->m_lastSafePosition.x;
				break;
			}
		}
	}


	this->m_lastSafePosition.y = this->m_transform->y;
	this->m_transform->translateY(this->m_rigitBody->getNewPosition().y);
	this->setColliderRegion();
	
	if (this->m_collider.y < 0 || this->m_collider.y + this->m_collider.h > this->belongsToMap->getTotalHeight())
	{
		this->m_transform->y = this->m_lastSafePosition.y;
	}
	else
	{
		for (SDL_Rect mapCollider : this->belongsToMap->getColliders())
		{
			if (CollisionHandler::getInstance()->checkCollision(this->m_collider, mapCollider))
			{
				this->m_transform->y = this->m_lastSafePosition.y;
				break;
			}
		}
	}


	// Update animation
	if (this->m_rigitBody->getForce().x > 0 && Direction::RIGHT != this->m_currentSpriteDirection)
	{
		if (this->m_currentAnimation->getCurrentRowAnimation() != 1)
		{
			this->m_currentAnimation->updateRowAnimation(1);
		}

		this->m_currentAnimation->setFlip(SDL_FLIP_NONE);

		this->m_currentSpriteDirection = Direction::RIGHT;
	}
	else if (this->m_rigitBody->getForce().x < 0 && Direction::LEFT != this->m_currentSpriteDirection)
	{
		if (this->m_currentAnimation->getCurrentRowAnimation() != 1)
		{
			this->m_currentAnimation->updateRowAnimation(1);
		}

		this->m_currentAnimation->setFlip(SDL_FLIP_HORIZONTAL);

		this->m_currentSpriteDirection = Direction::LEFT;
	}

	if (this->m_rigitBody->getForce().y > 0 && Direction::DOWN != this->m_currentSpriteDirection)
	{
		if (this->m_currentAnimation->getCurrentRowAnimation() != 2)
		{
			this->m_currentAnimation->updateRowAnimation(2);
		}

		this->m_currentSpriteDirection = Direction::DOWN;
	}
	else if (this->m_rigitBody->getForce().y < 0 && Direction::UP != this->m_currentSpriteDirection)
	{
		if (this->m_currentAnimation->getCurrentRowAnimation() != 3)
		{
			this->m_currentAnimation->updateRowAnimation(3);
		}

		this->m_currentSpriteDirection = Direction::UP;
	}

	this->m_currentAnimation->update();
}

void Player::draw()
{
	this->m_currentAnimation->render(this->m_transform->x, this->m_transform->y);
}

void Player::dispose()
{
}

void Player::interact(GameObject* other)
{
}

void Player::proximityInteract(GameObject* other)
{
}

void Player::isDied(bool died)
{
	this->m_isDied = died;
}

bool Player::isDied()
{
	return this->m_isDied;
}

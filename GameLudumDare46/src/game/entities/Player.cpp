#include "Player.h"

Player::Player(std::string id, std::string name, int x, int y, TiledMap* map)
	: Entity(id, name, x, y, map)
{
	float scale = 4;

	// Sprite animations
	this->m_idleAnimation = new SpriteAnimation("player-idle", "assets/sprites/player.png", 1, 3, 3, 3, scale);
	this->m_rightWalkAnimation = new SpriteAnimation("player-idle", "assets/sprites/player.png", 2, 1, 3, 3, scale);

	this->m_currentAnimation = this->m_idleAnimation;

	this->m_speed = 3;
}

void Player::setCollidernRegion()
{
}

void Player::update(float delta)
{
	this->m_rigitBody->removeForce();

	if (InputHandler::getInstance()->isAxisKey(AxisDirection::UP))
	{
		this->m_rigitBody->setForceY(-this->m_speed);
	}
	if (InputHandler::getInstance()->isAxisKey(AxisDirection::RIGHT))
	{
		this->m_rigitBody->setForceX(this->m_speed);
	}
	if (InputHandler::getInstance()->isAxisKey(AxisDirection::LEFT))
	{
		this->m_rigitBody->setForceX(-this->m_speed);
	}
	if (InputHandler::getInstance()->isAxisKey(AxisDirection::DOWN))
	{
		this->m_rigitBody->setForceY(this->m_speed);
	}

	this->m_rigitBody->update(delta);

	this->m_transform->translateX(this->m_rigitBody->getNewPosition().x);
	this->m_transform->translateY(this->m_rigitBody->getNewPosition().y);

	this->m_origin->x = this->m_transform->x + (this->m_currentAnimation->getWidth() / 2);
	this->m_origin->y = this->m_transform->y + (this->m_currentAnimation->getHeight() / 2);


	if (this->m_rigitBody->getForce().x > 0)
	{
		//
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

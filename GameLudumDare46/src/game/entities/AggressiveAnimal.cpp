#include "AggressiveAnimal.h"

AggressiveAnimal::AggressiveAnimal(std::string id, std::string name, int x, int y, TiledMap* map, SpriteAnimation* idleAnimation, SpriteAnimation* moveAnimation)
	: Animal(id, name, x, y, map)
{
	this->m_idleAnimation = idleAnimation;
	this->m_moveAnimation = moveAnimation;

	this->m_currentAnimation = idleAnimation;

	this->m_type = GameObjectType::AGGRESSIVE_ANIMAL;

	this->m_speed = 4.5;

	this->setColliderRegion();

	m_aStar = new AStarFinding(this->belongsToMap);
}

void AggressiveAnimal::setColliderRegion()
{
	this->m_collider = {
		static_cast<int>(this->m_transform->x),
		static_cast<int>(this->m_transform->y + 35),
		static_cast<int>(this->m_currentAnimation->getWidth() - 25),
		static_cast<int>(this->m_currentAnimation->getHeight()) - 25 };

	this->m_origin->x = this->m_transform->x + (this->m_currentAnimation->getWidth() / 2);
	this->m_origin->y = this->m_transform->y + (this->m_currentAnimation->getHeight() / 2);
}

void AggressiveAnimal::update(float delta)
{
	this->m_rigitBody->update(delta);
	this->m_transform->translateX(this->m_rigitBody->getNewPosition().x);
	this->m_transform->translateY(this->m_rigitBody->getNewPosition().y);
	
	this->setColliderRegion();

	this->m_currentAnimation->update();
}

void AggressiveAnimal::draw()
{
	this->m_currentAnimation->render(this->m_transform->x, this->m_transform->y);
}

void AggressiveAnimal::dispose()
{
}

void AggressiveAnimal::interact(GameObject* other)
{
	if (GameObjectType::PLAYER == other->getType())
	{
		static_cast<Player*>(other)->isDied(true);
	}
}

void AggressiveAnimal::proximityInteract(GameObject* other)
{
	if (GameObjectType::PLAYER == other->getType())
	{
		if (m_aStar->isGoalFounded()
			&& m_aStar->getGoalCell()->m_xCoord != other->getMapCellCoordX()
			&& m_aStar->getGoalCell()->m_yCoord != other->getMapCellCoordY())
		{
			this->m_aStar->reset();
		}

		m_aStar->findPath(this->getMapCellCoords(), other->getMapCellCoords());

		if (m_aStar->isGoalFounded())
		{
			if (m_aStar->isGoalReached())
			{
				this->m_rigitBody->removeForce();


			}
			else
			{
				this->m_nextFindingCell = m_aStar->nextPathPosition(this);

				Point* targetPosition = new Point(
					(this->m_nextFindingCell.x * this->belongsToMap->getTileSize()) + (this->belongsToMap->getTileSize() / 2),
					(this->m_nextFindingCell.y * this->belongsToMap->getTileSize()) + (this->belongsToMap->getTileSize() / 2));

				if (this->m_origin->x < targetPosition->x)
				{
					this->m_rigitBody->setForceX(this->m_speed);
				}
				else if (this->m_origin->x > targetPosition->x)
				{
					this->m_rigitBody->setForceX(-this->m_speed);
				}

				if (this->m_origin->y < targetPosition->y)
				{
					this->m_rigitBody->setForceY(this->m_speed);
				}
				else if (this->m_origin->y > targetPosition->y)
				{
					this->m_rigitBody->setForceY(-this->m_speed);
				}
			}
		}
	}
}

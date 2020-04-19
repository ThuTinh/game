#include "Enemy.h"
#include"Player.h"
#include"Weapon.h"
#include"DieEffect.h"

Enemy::Enemy()
{
	isContactGround = true;
	setPhysicsEnable(true);
	/*setDirection(TEXTURE_DIRECTION::TEXTURE_DIRECTION_RIGHT);*/

}

void Enemy::onCollision(MovableRect* other, float collisionTime, int nx, int ny)
{
	if (isContactGround && other->getCollisionType() == COLLISION_TYPE_GROUND)
	{
		/* ngăn chặn di chuyển */
		preventMovementWhenCollision(collisionTime, nx, ny);
		PhysicsObject::onCollision(other, collisionTime, nx, ny);
	}
}

void Enemy::update(float dt)
{
	if (this->getAlive())
	{
		PhysicsObject::update(dt);
	}
}

void Enemy::setDirectionFollowPlayer()
{
	if (Player::getInstance()->getMidX() - getMidX() < 0)
	{
		setDirection(-1);
	}
	else
	{
		setDirection(1);
	}
}

void Enemy::onUpdate(float dt)
{
	PhysicsObject::onUpdate(dt);
}

void Enemy::onAABB(MovableRect* other)
{
	if (other == Weapon::getInstance() && getAlive()) {
		setAlive(false);
		DieEffect* dieEffect = new DieEffect();

		dieEffect->setX(getX());
		dieEffect->setY(getY());
		dieEffect->timeDelay.start();
	}
}


Enemy::~Enemy()
{
}

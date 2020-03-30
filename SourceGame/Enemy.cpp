#include "Enemy.h"
Enemy::Enemy()
{
	setPhysicsEnable(false);
	/*setDirection(TEXTURE_DIRECTION::TEXTURE_DIRECTION_RIGHT);*/


}

void Enemy::onCollision(MovableRect* other, float collisionTime, int nx, int ny)
{
	
	PhysicsObject::onCollision(other, collisionTime, nx, ny);
}

void Enemy::onUpdate(float dt)
{
	PhysicsObject::onUpdate(dt);
}


Enemy::~Enemy()
{
}

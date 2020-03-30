#include "Fire.h"



Fire::Fire()
{
	setPhysicsEnable(false);
	/*setDirection(TEXTURE_DIRECTION::TEXTURE_DIRECTION_RIGHT);*/
}

void Fire::onCollision(MovableRect* other, float collisionTime, int nx, int ny)
{
	/*if (ny != 0)
	{
		setDirection(getDirection() * -1);
	}*/
	/* ngăn chặn di chuyển */
	preventMovementWhenCollision(collisionTime, nx, ny);
	PhysicsObject::onCollision(other, collisionTime, nx, ny);
}

void Fire::onUpdate(float dt)
{
	PhysicsObject::onUpdate(dt);
}


Fire::~Fire()
{
}


#include "fire.h"
#include"Weapon.h"
//void Fire::onCollision(MovableRect* other, float collisionTime, int nx, int ny)
//{
//	
//	/* ngăn chặn di chuyển */
//	preventMovementWhenCollision(collisionTime, nx, ny);
//	PhysicsObject::onCollision(other, collisionTime, nx, ny);
//}


Fire::Fire()
{
	setAnimation(0);
	setDirection(TEXTURE_DIRECTION::TEXTURE_DIRECTION_LEFT);
}

Fire::~Fire()
{
}

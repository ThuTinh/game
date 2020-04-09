#include "Misc.h"
#include"Weapon.h"
Misc::Misc()
{
	setPhysicsEnable(false);
	/*setDirection(TEXTURE_DIRECTION::TEXTURE_DIRECTION_RIGHT);*/
}

void Misc::onCollision(MovableRect* other, float collisionTime, int nx, int ny)
{
	/*if (other->getCollisionType() == COLLISION_TYPE_WEAPON) {
		setAlive(false);
	}*/
	/* ngăn chặn di chuyển */
	preventMovementWhenCollision(collisionTime, nx, ny);
	PhysicsObject::onCollision(other, collisionTime, nx, ny);
}

void Misc::onUpdate(float dt)
{
	PhysicsObject::onUpdate(dt);
}


void Misc::onAABB(MovableRect* other)
{

	if (other == Weapon::getInstance() && Weapon::getInstance()->getAnimation() == 5)
	{
		setAlive(false);
	}
}

Misc::~Misc()
{
}

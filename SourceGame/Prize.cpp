#include "Prize.h"
Prize::Prize()
{
	setPhysicsEnable(false);
	/*setDirection(TEXTURE_DIRECTION::TEXTURE_DIRECTION_RIGHT);*/


}

void Prize::onCollision(MovableRect* other, float collisionTime, int nx, int ny)
{

	PhysicsObject::onCollision(other, collisionTime, nx, ny);
}

void Prize::onUpdate(float dt)
{
	PhysicsObject::onUpdate(dt);
}


Prize::~Prize()
{
}

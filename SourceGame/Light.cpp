#include "Light.h"

Light::Light()
{
	setPhysicsEnable(false);
	/*setDirection(TEXTURE_DIRECTION::TEXTURE_DIRECTION_RIGHT);*/
}

void Light::onCollision(MovableRect* other, float collisionTime, int nx, int ny)
{
	/*if (ny != 0)
	{
		setDirection(getDirection() * -1);
	}*/
	/* ngăn chặn di chuyển */
	preventMovementWhenCollision(collisionTime, nx, ny);
	PhysicsObject::onCollision(other, collisionTime, nx, ny);
}

void Light::onUpdate(float dt)
{
	PhysicsObject::onUpdate(dt);
}


Light::~Light()
{
}

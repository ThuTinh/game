#include "Zoombie.h"



Zoombie::Zoombie()
{
	dcx = 1;
	setDirection(TEXTURE_DIRECTION::TEXTURE_DIRECTION_RIGHT);
}

void Zoombie::onCollision(MovableRect * other, float collisionTime, int nx, int ny)
{
	if (ny != 0)
	{
		setDirection(getDirection() * -1);
	}
	/* ngăn chặn di chuyển */
	preventMovementWhenCollision(collisionTime, nx, ny);
	PhysicsObject::onCollision(other, collisionTime, nx, ny);
}

void Zoombie::onUpdate(float dt)
{
	setVx(20 * getDirection());
	PhysicsObject::onUpdate(dt);
}


Zoombie::~Zoombie()
{
}

#include "Misc.h"
#include"Weapon.h"
#include"DieEffect.h"
Misc::Misc()
{
	setPhysicsEnable(false);
}

void Misc::onCollision(MovableRect* other, float collisionTime, int nx, int ny)
{
	preventMovementWhenCollision(collisionTime, nx, ny);
	PhysicsObject::onCollision(other, collisionTime, nx, ny);
}

void Misc::onUpdate(float dt)
{
	PhysicsObject::onUpdate(dt);
}

void Misc::update(float dt)
{
	if (this->getAlive())
	{
		PhysicsObject::update(dt);
	}
}


void Misc::onAABB(MovableRect* other)
{

	if (other == Weapon::getInstance() && getAlive()) {
		setAlive(false);
		DieEffect* dieEffect = new DieEffect();

		dieEffect->setX(getX());
		dieEffect->setY(getY());
		dieEffect->timeDelay.start();
	}
	if (other == Weapon::getInstance() && Weapon::getInstance()->getAnimation() == 5)
	{
		setAlive(false);
	}
}

Misc::~Misc()
{
}

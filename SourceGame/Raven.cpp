#include"Raven.h"
#include"Weapon.h"
#include"Player.h"
#include"Camera.h"
#include "GameConfiguration.h"

void Raven::onCollision(MovableRect* other, float collisionTime, int nx, int ny)
{

	Enemy::onCollision(other, collisionTime, nx, ny);
}

void Raven::onUpdate(float dt)
{

	Enemy::onUpdate(dt);
}

Raven::Raven()
{
	setPhysicsEnable(false);
	setAnimation(RAVEN_ACTION_STAND);
}

Raven::~Raven()
{
}

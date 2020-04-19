#include"BlackNight.h"
#include"Weapon.h"
#include"Player.h"
#include"Camera.h"
#include "GameConfiguration.h"

void BlackNight::onCollision(MovableRect* other, float collisionTime, int nx, int ny)
{
	if (other->getCollisionType() == COLLISION_TYPE_GROUND) {
		if (this->getX() + 5 > other->getRight() || nx != 0) {
			setDirection(-1);
			setVx(-GLOBALS_D("blacknight_vx"));
		}
		else
		{
			if (this->getX() - 5 < other->getleft()) {
				setDirection(1);
				setVx(GLOBALS_D("blacknight_vx"));
			}
		}
		
	}
	Enemy::onCollision(other, collisionTime, nx, ny);
}

void BlackNight::onUpdate(float dt)
{

	Enemy::onUpdate(dt);
}

BlackNight::BlackNight()
{
	setVx(GLOBALS_D("blacknight_vx"));
}

BlackNight::~BlackNight()
{
}

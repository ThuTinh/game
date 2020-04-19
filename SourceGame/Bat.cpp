#include"Bat.h"
#include"Weapon.h"
#include"Player.h"
#include"Camera.h"
#include "GameConfiguration.h"



void Bat::onCollision(MovableRect* other, float collisionTime, int nx, int ny)
{
}

void Bat::onUpdate(float dt)
{
	switch (batState)
	{
	case BAT_STATE_STAND:
		setDx(0);
		setDy(0);
		if (abs(getX() - Player::getInstance()->getX()) < GLOBALS_D("bat_run_dx") && getX() < Player::getInstance()->getX())
		{
			batState = BAT_STATE_FLY;
			setPhysicsEnable(true);
			setAy(GLOBALS_D("bat_ay"));
			setVy(-5);
			setVx(100);
			setAnimation(BAT_ACTION_FLY);
		}
		break;
	case BAT_STATE_FLY:
		break;
	default:
		break;
	}
	//if (abs(getX() - Player::getInstance()->getX()) < GLOBALS_D("bat_run_dx") && getX()< Player::getInstance()->getX()) {
	//	
	//}
	//if (getX() > Player::getInstance()->getX() && abs(getX() - Player::getInstance()->getX()) > (GLOBALS_D("bat_run_dx")+20)) {
	//	setIsRender(false);
	//}
	Enemy::onUpdate(dt);
}

Bat::Bat()
{
	setPhysicsEnable(false);
	setAnimation(BAT_ACTION_STAND);
	batState = BAT_STATE_STAND;
}

Bat::~Bat()
{
}

#include"Bat.h"
#include"Weapon.h"
#include"Player.h"
#include"Camera.h"
#include "GameConfiguration.h"



void Bat::onUpdate(float dt)
{
	if (abs(getX() - Player::getInstance()->getX()) < GLOBALS_D("bat_run_dx") && getX()< Player::getInstance()->getX()) {
		setPhysicsEnable(true);
		setAy(GLOBALS_D("bat_ay"));
		setVy(-5);
		setVx(100);
	}
	if (getX() > Player::getInstance()->getX() && abs(getX() - Player::getInstance()->getX()) > (GLOBALS_D("bat_run_dx")+20)) {
		setIsRender(false);
	}
	Enemy::onUpdate(dt);
}

Bat::Bat()
{
	setPhysicsEnable(false);
	setAnimation(BAT_ACTION_STAND);
}

Bat::~Bat()
{
}

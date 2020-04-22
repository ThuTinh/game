#include"Fleaman.h"
#include"Weapon.h"
#include"Player.h"
#include"Camera.h"
#include "GameConfiguration.h"

void Fleaman::onCollision(MovableRect* other, float collisionTime, int nx, int ny)
{

	Enemy::onCollision(other, collisionTime, nx, ny);
}

void Fleaman::onUpdate(float dt)
{
	if(abs(Player::getInstance()->getX() - getX()) < GLOBALS_D("fleaman_distance_to_jumb")) {
		setDirectionFollowPlayer();
		setVx(getDirection() * GLOBALS_D("fleaman_vx"));
		switch (fleamanState)
		{
		case FLEAMAN_STATE_JUMP_SHORT:
			if (getIsOnGround())
			{
				if (jumpRemain > 0)
				{
					setVy(GLOBALS_D("fleaman_vy_short"));
					jumpRemain--;
				}
				else
				{
					fleamanState = FLEAMAN_STATE_JUMP_LONG;
					jumpRemain = GLOBALS_D("fleaman_jumplong_counter");
				}
			}
			break;
		case FLEAMAN_STATE_JUMP_LONG:
			if (getIsOnGround())
			{
				if (jumpRemain > 0)
				{
					setVy(GLOBALS_D("fleaman_vy_long"));
					jumpRemain--;
				}
				else
				{
					fleamanState = FLEAMAN_STATE_JUMP_SHORT;
					jumpRemain = GLOBALS_D("fleaman_jumpshort_counter");
				}
			}
			break;
		default:
			break;
		}
		Enemy::onUpdate(dt);
	}
	
}

Fleaman::Fleaman()
{
	setAnimation(FLEAMAN_ACTION_STAND);
	fleamanState = FLEAMAN_STATE_JUMP_SHORT;
	jumpRemain = GLOBALS_D("fleaman_jumpshort_counter");
}

Fleaman::~Fleaman()
{
}

#include"Zoombie.h"
#include"Weapon.h"
#include"Player.h"
#include"Camera.h"
ZOOMBIE_STATE Zoombie::getZoombieState()
{
	return zoombieState;
}
void Zoombie::setZoombieState(ZOOMBIE_STATE zoombiState)
{
	this->zoombieState = zoombieState;
}
void Zoombie::onUpdate(float dt)
{
	
	switch (zoombieState)
	{
	case ZOOMBIE_STAND:
		if (abs(getX() - Player::getInstance()->getX()) < GLOBALS_D("zoombie_run_dx")) {
			zoombieState = ZOOMBIE_RUN;

		}
		break;
	case ZOOMBIE_RUN:
		setVx(-GLOBALS_D("zoombie_run_vx"));
		if (abs(Camera::getInstance()->getScene()->X - getX()) < 30) {
			zoombieState = ZOOMBIE_RUN_TURNING;
		}
		
		if ( abs(Player::getInstance()->getX() - getX())> GLOBALS_D("zoombie_run_dx_to_turning")) {
			zoombieState= ZOOMBIE_RUN_TURNING;
		}
		break;

	case ZOOMBIE_RUN_TURNING:
		setVx(GLOBALS_D("zoombie_run_vx"));
		break;

	default:
		break;
	}
	Enemy::onUpdate(dt);
}

void Zoombie::onCollision(MovableRect* other, float collisionTime, int nx, int ny)
{

	Enemy::onCollision(other, collisionTime, nx, ny);
	
}

Zoombie::Zoombie()
{
	
}

Zoombie::~Zoombie()
{
}

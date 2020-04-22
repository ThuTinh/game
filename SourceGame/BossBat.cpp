#include "BossBat.h"
#include"Camera.h"
#include"ScoreBar.h"
#include"Game.h"
//REGISTER_OBJECT_GAME(BossBat, SI_VAMPIRE_BAT)

#define MAX(a,b) (a>b? a : b)
#define MIN(a,b) (a<b? a : b)

extern int getRandom(int start, int end);


void BossBat::onCollision(MovableRect* other, float collisionTime, int nx, int ny)
{
}

void BossBat::setBossState(BOSS_STATE bossState)
{
	this->bossState = bossState;
}

void BossBat::onUpdate(float dt)
{
	float vx2 = 0, vy2 = 0;
	waitDelay.update();
	moveFastDelay.update();
	moveSlowDelay.update();
	switch (bossState)
	{
	case BOSS_STATE_INVISIBLE:
	{
		Game::getInstance()->getSceneManager()->getCurrentScene()->setCurrentSpace(1);
		int distance = player->getX() - getX();
		if (distance > GLOBALS_D("boss_distance_activ"))
		{
			
			setAnimation(BOSS_ACTION_ACTIV);
			setBossState(BOSS_STATE_WAIT);
			calculateOtherPoint();
			if (xDes < getX())
			{
				vx2 = -GLOBALS_D("vampire_bat_fast_momen");
			}
			else
			{
				vx2 = GLOBALS_D("vampire_bat_fast_momen");
			}
			vy2 = (vx2 * (yDes - getY()) / (xDes - getX()));
			waitDelay.start();
		}
		break;
	}
	case BOSS_STATE_WAIT:
		setDx(0);
		setVx(0);
		setDy(0);
		setVy(0);
		if (waitDelay.isTerminated())
		{
			setBossState(BOSS_STATE_MOVE_FAST);
			DWORD moveFastDelayTime = getRandom(GLOBALS_D("boss_move_fast_time_min"), GLOBALS_D("boss_move_fast_time_max"));
			moveFastDelay.start(moveFastDelayTime);
			calculateOtherPoint();
			if (xDes < getX())
			{
				vx2 = -GLOBALS_D("vampire_bat_fast_momen");
			}
			else
			{
				vx2 = GLOBALS_D("vampire_bat_fast_momen");
			}
			vy2 = (vx2 * (yDes - getY()) / (xDes - getX()));
			setVx(vx2);
			setVy(vy2);
		}
		break;
	case BOSS_STATE_MOVE_FAST:
	{
		auto camera = Camera::getInstance();

		if (getDx() < 0 && camera->getleft() > getX() + getDx())
		{
			calculateOtherPoint();
			if (xDes < getX())
			{
				vx2 = -GLOBALS_D("vampire_bat_fast_momen");
			}
			else
			{
				vx2 = GLOBALS_D("vampire_bat_fast_momen");
			}
			vy2 = (vx2 * (yDes - getY()) / (xDes - getX()));
			setVx(vx2);
			setVy(vy2);
		}

		if (getDx() > 0 && camera->getRight() < getRight() + getDx())
		{
			calculateOtherPoint();
			if (xDes < getX())
			{
				vx2 = -GLOBALS_D("vampire_bat_fast_momen");
			}
			else
			{
				vx2 = GLOBALS_D("vampire_bat_fast_momen");
			}
			vy2 = (vx2 * (yDes - getY()) / (xDes - getX()));
			setVx(vx2);
			setVy(vy2);
		}

		if (moveFastDelay.isTerminated())
		{
			waitDelay.start();
			setBossState(BOSS_STATE_MOVE_SLOW);
			DWORD moveSlowDelayTime = getRandom(GLOBALS_D("boss_move_slow_time_min"), GLOBALS_D("boss_move_slow_time_max"));
			moveSlowDelay.start(moveSlowDelayTime);
			calculateOtherPoint();
			setVx(0);
			setVy(0);
			if (xDes < getX())
			{
				setDx(-1);
			}
			else
			{
				setDx(1);
			}
			setDy(-(getDx() * (yDes - getY()) / (xDes - getX())));
			return;
		}

		preventGoOutsideCamera();
		Enemy::onUpdate(dt);
		break;
	}
	case BOSS_STATE_MOVE_SLOW:
		if (moveSlowDelay.isTerminated())
		{
			setBossState(BOSS_STATE_WAIT);
			waitDelay.start();
		}
		preventGoOutsideCamera();
		break;
	default:
		break;
	}
}

void BossBat::calculateOtherPoint()
{
	auto camera = Camera::getInstance();
	if (getMidX() > player->getMidX() && getX() - camera->getX() > 30)
	{
		xDes = camera->getleft();
	}
	else
	{
		xDes = camera->getRight();
	}

	int yMin = player->getMidY() - 60;

	int yMax = player->getMidY();

	yDes = getRandom(yMin, yMax);
}

void BossBat::onDecreaseHealth()
{
	ScoreBar::getInstance()->increaseBossHealth(-16);
	//setHealth(getHealth() - 16);
}

void BossBat::restore()
{
	setAnimation(BOSS_ACTION_WAIT);
	setBossState(BOSS_STATE_INVISIBLE);
	setVx(0);
	setDx(0);
	setVy(0);
	setDy(0);
}

void BossBat::preventGoOutsideCamera()
{
	auto camera = Camera::getInstance();

	if ((getX() + getDx() < camera->getleft() && getDx() < 0) || (getRight() + getDx() > camera->getRight() && getDx() > 0))
	{
		setDx(-getDx());
	}

	if ((getY() + getDy() > camera->getTop() - 48 && getDy() > 0)
		|| (getBottom() + getDy() < camera->getBottom() + 32 && getDy() < 0))
	{
		setDy(-getDy());
	}

}

BossBat::BossBat()
{
	player = Player::getInstance();
	waitDelay.init(GLOBALS_D("boss_wait_time"));
	setAy(GLOBALS_D("boss_ay"));
	//setHealth(16);
}


BossBat::~BossBat()
{
}

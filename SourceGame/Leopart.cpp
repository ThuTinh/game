#include"Leopart.h"
#include"Player.h"
#include"GameConfiguration.h"

void Leopart::onUpdate(float dt)
{
	switch (leopartState)
	{
	case LEOPART_STATE_LIE:
		setVx(0);
		setAnimation(LEOPART_LIE);

		if (abs(getX() - Player::getInstance()->getX()) < GLOBALS_D("leopart_run_dx"))
		{
			leopartState = LEOPART_STATE_RUN;
		}

		break;
	case LEOPART_STATE_RUN:
		setAnimation(LEOPART_RUN);
		setVx(getDirection() * GLOBALS_D("leopart_run_vx"));

		break;
	case LEOPART_STATE_JUMP:
		setAnimation(LEOPART_JUMB);
		if (getIsOnGround())
		{
			leopartState = LEOPART_STATE_RUN;
			setDirectionFollowPlayer();
		}
		break;
	default:
		break;
	}

	Enemy::onUpdate(dt);
}

void Leopart::onCollision(MovableRect* other, float collisionTime, int nx, int ny)
{

	Enemy::onCollision(other, collisionTime, nx, ny);
	if (leopartState == LEOPART_STATE_RUN && other->getCollisionType() == COLLISION_TYPE::COLLISION_TYPE_GROUND && ny == 1)
	{
		if (getDx() < 0 && getX() < other->getX() || getDx() > 0 && getRight() > other->getRight())
		{
			setVy(GLOBALS_D("leopart_jump_vy"));
			leopartState = LEOPART_STATE_JUMP;
			setIsOnGround(false);
		}
	}
}

Leopart::Leopart()
{
	setAnimation(0);
	setDirection(TEXTURE_DIRECTION::TEXTURE_DIRECTION_LEFT);
}

Leopart::~Leopart()
{
}



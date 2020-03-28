#include "Player.h"



Player * Player::instance = 0;

void Player::goStairUp()
{
	playerStairDesty = getY() + 8;
	if (stairDirection == 1)
	{
		/* stair phải */
		playerStairDestx += 8;
		setDirection(TEXTURE_DIRECTION::TEXTURE_DIRECTION_RIGHT);
	}
	else
	{
		/* stair trái */
		playerStairDestx -= 8;
		setDirection(TEXTURE_DIRECTION::TEXTURE_DIRECTION_LEFT);
	}

	setPlayerStairState(PLAYER_STAIR_STATE::PLAYER_STAIR_STATE_GO_UP);
	/* cho player có lại animation khi lên cầu thang */
	setPauseAnimation(false);
	setAnimation(PLAYER_ACTION_GO_STAIR_UP);
}
void Player::goStairDown()
{
	playerStairDesty -= 8;
	if (stairDirection == 1)
	{
		/* stair phải */
		playerStairDestx -= 8;
		setDirection(TEXTURE_DIRECTION::TEXTURE_DIRECTION_LEFT);
	}
	else
	{
		/* stair trái */
		playerStairDestx += 8;
		setDirection(TEXTURE_DIRECTION::TEXTURE_DIRECTION_RIGHT);
	}

	setPlayerStairState(PLAYER_STAIR_STATE::PLAYER_STAIR_STATE_GO_DOWN);
	/* cho player có lại animation khi xuống cầu thang */
	setPauseAnimation(false);
	setAnimation(PLAYER_ACTION_GO_STAIR_DOWN);
}

Player * Player::getInstance()
{
	if (instance == 0)
	{
		instance = new Player();
	}
	return instance;
}

PLAYER_STATE Player::getPlayerState()
{
	return this->playerState;
}

void Player::setPlayerState(PLAYER_STATE playerState)
{
	this->playerState = playerState;
}

/* phương thức gọi ngay khi gặp stair và người chơi nhấn phím lên xuống để vào stair */
void Player::setStartStair()
{
	/* tắt vật lý cho player */
	this->setPhysicsEnable(false);

	playerStairDestx = getX();
	playerStairDesty = getY();


	if (!KEY::getInstance()->isUpDown && !KEY::getInstance()->isDownDown)
	{
		/* tắt chuyển animation cho player */
		setPauseAnimation(true);

		/* stop tất cả chuyển động */
		this->setVx(0);
		this->setVy(0);
		this->setDx(0);
		this->setDy(0);

		/* reset frame */
		setFrameAnimation(0);
	}

	/* set state lên cầu thang cho player */
	setPlayerState(PLAYER_STATE::PLAYER_STATE_ON_STAIR);

	/* set player stair state */
	setPlayerStairState(PLAYER_STAIR_STATE::PLAYER_STAIR_STATE_NORUN);


	/* tắt xử lý va chạm */
	setStopCollision(true);
}

bool Player::getIsLastRunStair()
{
	return this->isLastRunStair;
}
void Player::setIsLastRunStair(bool isLastRunStair)
{
	this->isLastRunStair = isLastRunStair;
}

void Player::setStopStair()
{
	/* stop tất cả chuyển động */
	this->setVx(0);
	this->setVy(0);
	this->setDx(0);
	this->setDy(0);

	/* bật chuyển animation cho player */
	setPauseAnimation(false);

	/* bật xử lý va chạm */
	setStopCollision(false);

	/* bật vật lý */
	setPhysicsEnable(true);

	/* chuyển về state normal */
	setPlayerState(PLAYER_STATE_NORMAL);

	/* tắt chạy stair theo frame cuối */
	setIsLastRunStair(false);
}

void Player::onUpdate(float dt)
{
	bool keyLeftDown, keyRightDown, keyUpDown, keyDownDown, keyJumpPress;
	/* kiểm tra key bên trái có được giữ */
	keyLeftDown = KEY::getInstance()->isLeftDown;
	/* kiểm tra key bên phải có được giữ */
	keyRightDown = KEY::getInstance()->isRightDown;
	keyUpDown = KEY::getInstance()->isUpDown;
	keyDownDown = KEY::getInstance()->isDownDown;

	/* kiểm tra key jump có được nhấn */
	keyJumpPress = KEY::getInstance()->isJumpPress;

	/* update dựa vào playerState */
	switch (playerState)
	{
	case PLAYER_STATE_NORMAL:
	{
		float vx = GLOBALS_D("player_vx");

		/* nếu vật đứng trên sàn */
		if (getIsOnGround())
		{
			/* nếu giữ key trái */
			if (keyLeftDown)
			{
				/* set animation chạy */
				setAnimation(PLAYER_ACTION_RUN);
				setVx(-vx);
				setDirection(TEXTURE_DIRECTION_LEFT);
			}
			/* nếu giữ key phải */
			else if (keyRightDown)
			{
				/* set animation chạy */
				setAnimation(PLAYER_ACTION_RUN);
				setVx(vx);
				setDirection(TEXTURE_DIRECTION_RIGHT);
			}
			else
			{
				/* set animation đứng yên */
				setAnimation(PLAYER_ACTION_STAND);
				setVx(0);
			}
			/* nếu đứng trên sàn mà nhấn key jump thì sẽ cho nhân vật nhảy. còn nếu ở trên không mà nhấn key jump thì nó sẽ
			không vào chỗ này vì không thỏa mãn isOnGround = true*/
			if (keyJumpPress)
			{
				setVy(GLOBALS_D("player_vy_jump"));
			}
		}
		else /* nếu nhân vật không đứng trên sàn (đang lơ lững trên không) */
		{
			setAnimation(PLAYER_ACTION_JUMP);
		}

		/* gọi lại phương thức xử lý onUpdate đã được định nghĩa ở lớp cha control click vào PhysicsObject::onUpdate để biết */
		/* gọi lại xử lý của lớp cha */
		PhysicsObject::onUpdate(dt);
		break;
	}
	case PLAYER_STATE_ON_STAIR:
	{
		switch (playerStairState)
		{
		case PLAYER_STAIR_STATE_NORUN:
			if (!keyUpDown && !keyDownDown)
			{
				setPauseAnimation(true);
				setFrameAnimation(0);
				setDx(0);
				setDy(0);
				setX(playerStairDestx);
				setY(playerStairDesty);
			}
			if (keyUpDown)
			{
				goStairUp();
			}
			if (keyDownDown)
			{
				goStairDown();
			}
			return;
		case PLAYER_STAIR_STATE_GO_UP:
			setDx(getDirection() * GLOBALS_D("player_stair_dx"));
			/* đi lên */
			setDy(GLOBALS_D("player_stair_dy"));
			break;
		case PLAYER_STAIR_STATE_GO_DOWN:
			setDx(getDirection() * GLOBALS_D("player_stair_dx"));
			/* đi xuống */
			setDy(-GLOBALS_D("player_stair_dy"));
			break;
		default:
			break;
		}
		/* phương thức xử lý chung khi đi (kiểm tra đến đích chưa để dừng lại) */
		if (playerStairState == PLAYER_STAIR_STATE_GO_UP || playerStairState == PLAYER_STAIR_STATE_GO_DOWN)
		{
			if (getDirection() == TEXTURE_DIRECTION::TEXTURE_DIRECTION_RIGHT)
			{
				/* đang đi về phía bên phải */
				if (getX() + getDx() > playerStairDestx)
				{
					/* tới vị trí */
					setStartStair();

					setX(playerStairDestx);
					setY(playerStairDesty);

					/* nếu là lần di chuyển cuối cùng */
					if (getIsLastRunStair())
					{
						setStopStair();
					}
				}
			}
			else
			{
				/* đang đi về bên trái */
				if (getX() + getDx() < playerStairDestx)
				{
					/* tới vị trí */
					setStartStair();
					/* đang đi về phía bên trái */

					setX(playerStairDestx);
					setY(playerStairDesty);

					/* nếu là lần di chuyển cuối cùng */
					if (getIsLastRunStair())
					{
						setStopStair();
					}
				}
			}
		}
		break;
	}
	case PLAYER_STATE_DIE:
	{
		break;
	}
	default:
		break;
	}

}

void Player::onCollision(MovableRect * other, float collisionTime, int nx, int ny)
{
	if (other->getCollisionType() == COLLISION_TYPE_GROUND)
	{
		/* ngăn chặn di chuyển */
		preventMovementWhenCollision(collisionTime, nx, ny);
		PhysicsObject::onCollision(other, collisionTime, nx, ny);
	}

}

void Player::setStairDirection(int stairDirection)
{
	this->stairDirection = stairDirection;
}

void Player::setPlayerStairState(PLAYER_STAIR_STATE playerStairState)
{
	this->playerStairState = playerStairState;
}

PLAYER_STAIR_STATE Player::getPlayerStairState()
{
	return playerStairState;
}

Player::Player()
{
	setSprite(SPR(SPRITE_INFO_SIMON));
	/* set State hiện tại là normal */
	playerState = PLAYER_STATE::PLAYER_STATE_NORMAL;
}


Player::~Player()
{
}

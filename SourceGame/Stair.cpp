#include "Stair.h"
#include"Collision.h"
#include"Player.h"
#include<string>


void Stair::onInitFromFile(ifstream & fs, int mapHeight)
{
	/* bởi vì các thông số x y width height đứng trước IsRightStair và IsTop nên ta ưu tiên đọc nó trước */
	BaseObject::onInitFromFile(fs, mapHeight);
	string name;
	bool value;
	/* đọc các thống số trong file */
	fs >> name >> value;
	setParam(name.c_str(), value);
	fs >> name >> value;
	setParam(name.c_str(), value);
}

void Stair::setParam(const char * name, bool value)
{
	if (strcmp(name, "IsRightStair") == 0)
	{
		this->isRightStair = value;
	}
	if (strcmp(name, "IsTop") == 0)
	{
		this->isTop = value;
	}
}

void Stair::onUpdate(float dt)
{
	KEY* key = KEY::getInstance();
	Player* player = Player::getInstance();
	bool isUpDown = key->isUpPress;
	bool isDownDown = key->isDownPress;
	/* nếu hiện tại đối tượng đang va chạm với player */
	if (Collision::AABBCheck(this, player))
	{
		/* nếu nhấn key lên */
		if (isUpDown)
		{
			if (
				/* stair hiện tại là stair dưới */
				!isTop &&
				/* nếu player ở trên ground */
				player->getIsOnGround() &&
				/* trạng thái hiện tại của player là bình thường */
				player->getPlayerState() == PLAYER_STATE_NORMAL
				)
			{
				if (isRightStair)
				{
					/* đặt player đúng vị trí ban đầu. Tham khảo đối tượng stair trên world để xem */
					player->setX(getMidX() - player->getWidth());
					player->setY(getBottom() + player->getHeight());
					
				}
				else
				{
					/* đặt player đúng vị trí ban đầu. Tham khảo đối tượng stair trên world để xem */
					player->setX(getMidX());
					player->setY(getBottom() + player->getHeight());
				}

				/* stop tất cả chuyển động */
			/*	player->setVx(0);
				player->setVy(0);
				player->setDx(0);
				player->setDy(0);*/

				/* bắt đầu lên stair */
				player->setStartStair();

				/* set animation */
				player->setAnimation(PLAYER_ACTION::PLAYER_ACTION_GO_STAIR_UP);

				/* dừng chuyển động player */
				player->setPauseAnimation(true);

				/* set stair direction cho player */
				player->setStairDirection(isRightStair ? 1 : 0);

			}
		}

		/* nếu nhấn key xuống */
		if (isDownDown)
		{
			if (
				/* stair hiện tại là stair trên */
				isTop &&
				/* nếu player ở trên ground */
				player->getIsOnGround() &&
				/* trạng thái hiện tại của player là bình thường */
				player->getPlayerState() == PLAYER_STATE_NORMAL
				)
			{
				if (isRightStair)
				{
					/* đặt player đúng vị trí ban đầu. Tham khảo đối tượng stair trên world để xem */
					player->setX(getX() - 8);
					player->setY(getBottom() + player->getHeight());
				}
				else
				{
					/* đặt player đúng vị trí ban đầu. Tham khảo đối tượng stair trên world để xem */
					player->setX(getMidX());
					player->setY(getBottom() + player->getHeight());
				}

				/* stop tất cả chuyển động */
				player->setVx(0);
				player->setVy(0);
				player->setDx(0);
				player->setDy(0);

				/* bắt đầu lên stair */
				player->setStartStair();

				/* set animation */
				player->setAnimation(PLAYER_ACTION::PLAYER_ACTION_GO_STAIR_DOWN);

				/* dừng chuyển động player */
				player->setPauseAnimation(true);

				/* set stair direction cho player */
				player->setStairDirection(isRightStair ? 1 : 0);

			}
		}

		/* nếu player state là ở stair */
		if (player->getPlayerState() == PLAYER_STATE_ON_STAIR)
		{
			if (
				/* player đang đi lên */
				player->getDy() > 0 &&
				/* gặp cục stair chặn trên */
				this->isTop
				)
			{
				player->setIsLastRunStair(true);
			}
			if (
				/* player đang đi xuống */
				player->getDy() < 0 &&
				/* gặp cục stair chặn dưới */
				!this->isTop
				)
			{
				player->setIsLastRunStair(true);
			}
		}
	}
	 BaseObject::onUpdate(dt);
}

void Stair::update(float dt)
{
	onUpdate(dt);
}


Stair::Stair()
{
}


Stair::~Stair()
{
}

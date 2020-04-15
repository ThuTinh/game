#include "Gate6.h"
#include"Player.h"
#include"Game.h"
#include"Collision.h"


void Gate6::onUpdate(float dt)
{
	Player* player = Player::getInstance();
	if (Collision::AABBCheck(player, this)) {
		if (player->getPlayerState() == PLAYER_STATE_ON_STAIR && player->getDy() > 0 && checkOnlyOne) {
			player->setStairDirection(1);
			checkOnlyOne = false;
		}
	}
}

//void Gate6::onCollision(MovableRect* other, float collisionTime, int nx, int ny)
//{
//	Player* player = Player::getInstance();
//	if (other== player) {
//		if (player->getPlayerState() == PLAYER_STATE_ON_STAIR && player->getDy() > 0) {
//			player->setDirection(-player->getDirection());
//		}
//	}
//}

Gate6::Gate6()
{
	checkOnlyOne = true;
}

Gate6::~Gate6()
{
}

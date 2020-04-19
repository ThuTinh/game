#include "Gate3.h"
#include"Player.h"
#include"Game.h"
#include"Collision.h"


void Gate3::onUpdate(float dt)
{
	Player* player = Player::getInstance();
	if (Collision::AABBCheck(player, this)) {
		if (player->getPlayerState() == PLAYER_STATE_ON_STAIR && player->getDy() <0) {
			Game::getInstance()->getSceneManager()->getCurrentScene()->setCurrentSpace(0);
			Game::getInstance()->getSceneManager()->getCurrentScene()->resetLocationInSpace();
			player->setLocation(130, 0);
		}
	}
}

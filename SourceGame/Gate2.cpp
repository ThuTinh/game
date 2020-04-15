#include "Gate2.h"
#include"Player.h"
#include"Game.h"
#include"Collision.h"


void Gate2::onUpdate(float dt)
{
	Player* player = Player::getInstance();
	if (Collision::AABBCheck(player, this)) {
		if (player->getPlayerState() == PLAYER_STATE_ON_STAIR && player->getDy() > 0) {
			Game::getInstance()->getLevelManager()->getCurrentLevel()->setCurrentScene(1);
			Game::getInstance()->getLevelManager()->getCurrentLevel()->resetLocationInScene();
		}
	}
}

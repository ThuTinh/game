#include "Gate7.h"
#include"Player.h"
#include"Game.h"

void Gate7::onAABB(MovableRect* other)
{
	if (other == Player::getInstance())
	{
		Game::getInstance()->getLevelManager()->changeWorld(3);
		Game::getInstance()->getLevelManager()->getCurrentLevel()->resetLocationInScene();

	}
}

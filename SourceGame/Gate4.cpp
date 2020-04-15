#include "Gate4.h"
#include"Player.h"
#include"Game.h"

void Gate4::onAABB(MovableRect* other)
{
	if (other == Player::getInstance())
	{
		Game::getInstance()->getLevelManager()->changeWorld(2);
		Game::getInstance()->getLevelManager()->getCurrentLevel()->resetLocationInScene();
	}
}

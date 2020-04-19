#include "Gate7.h"
#include"Player.h"
#include"Game.h"

void Gate7::onAABB(MovableRect* other)
{
	if (other == Player::getInstance())
	{
		Game::getInstance()->getSceneManager()->changeWorld(3);
		Game::getInstance()->getSceneManager()->getCurrentScene()->resetLocationInSpace();

	}
}

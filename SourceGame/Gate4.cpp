#include "Gate4.h"
#include"Player.h"
#include"Game.h"

void Gate4::onAABB(MovableRect* other)
{
	if (other == Player::getInstance())
	{
		Game::getInstance()->getSceneManager()->changeWorld(2);
		Game::getInstance()->getSceneManager()->getCurrentScene()->resetLocationInSpace();
	}
}

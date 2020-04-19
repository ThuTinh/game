#include "Gate1.h"
#include"Player.h"
#include"Game.h"

void Gate1::onAABB(MovableRect* other)
{
	if (other == Player::getInstance())
	{
		Game::getInstance()->getSceneManager()->changeWorld(1);
		Game::getInstance()->getSceneManager()->getCurrentScene()->resetLocationInSpace();
	}
}

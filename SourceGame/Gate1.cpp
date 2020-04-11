#include "Gate1.h"
#include"Player.h"
#include"Game.h"

void Gate1::onAABB(MovableRect* other)
{
	if (other == Player::getInstance())
	{
		/*Game::getInstance()->getLevelManager()->getCurrentLevel()->setCurrentScene(1);
		Game::getInstance()->getLevelManager()->getCurrentLevel()->resetLocationInScene();*/
		Game::getInstance()->getLevelManager()->changeScene(1);
		Game::getInstance()->getLevelManager()->getCurrentLevel()->resetLocationInScene();
		Player::getInstance()->setCollitionGate(true);
	}
}

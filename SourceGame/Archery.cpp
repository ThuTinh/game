#include"Archery.h"
#include"Weapon.h"
#include"Player.h"



void Archery::onAABB(MovableRect* other)
{
	Item::onAABB(other);
	if (other == Player::getInstance() && getItemState() == ITEM_STATE_VISIBLE) {
		Player::getInstance()->setAnimation(PLAYER_ACTION_COLORS);
		Player::getInstance()->colorDelay.start();
		setState(ITEM_STATE_PLAYER_EATED);
		this->onPlayerContact();
		Player::getInstance()->AddNumberArChery(1);
	}
}

Archery::Archery()
{

}

Archery::~Archery()
{
}

#include"Item400PTS.h"
#include"Weapon.h"
#include"Player.h"



void Item400PTS::onAABB(MovableRect* other)
{
	Item::onAABB(other);
	if (other == Player::getInstance() && getItemState() == ITEM_STATE_VISIBLE) {

		setState(ITEM_STATE_PLAYER_EATED);
		this->onPlayerContact();
	}
}

Item400PTS::Item400PTS()
{
}

Item400PTS ::~Item400PTS()
{
}

void Item400PTS::onPlayerContact()
{
}

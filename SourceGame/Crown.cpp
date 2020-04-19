#include"Crown.h"
#include"Weapon.h"
#include"Player.h"



void Crown::onAABB(MovableRect* other)
{
	Item::onAABB(other);
	if (other == Player::getInstance() && getItemState() == ITEM_STATE_VISIBLE) {

		setState(ITEM_STATE_PLAYER_EATED);
		this->onPlayerContact();
	}
}

Crown::Crown()
{
}

Crown ::~Crown()
{
}

void Crown::onPlayerContact()
{
}

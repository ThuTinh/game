#include"Item1000PTS.h"
#include"Weapon.h"
#include"Player.h"



void Item1000PTS::onAABB(MovableRect* other)
{
	Item::onAABB(other);
	if (other == Player::getInstance() && getItemState() == ITEM_STATE_VISIBLE) {

		setState(ITEM_STATE_PLAYER_EATED);
		this->onPlayerContact();
	}
}

Item1000PTS::Item1000PTS()
{
}

Item1000PTS ::~Item1000PTS()
{
}

void Item1000PTS::onPlayerContact()
{
}

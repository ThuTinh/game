#include"Item700PTS.h"
#include"Weapon.h"
#include"Player.h"



void Item700PTS::onAABB(MovableRect* other)
{
	Item::onAABB(other);
	if (other == Player::getInstance() && getItemState() == ITEM_STATE_VISIBLE) {

		setState(ITEM_STATE_PLAYER_EATED);
		this->onPlayerContact();
	}
}

Item700PTS::Item700PTS()
{
}

Item700PTS ::~Item700PTS()
{
}

void Item700PTS::onPlayerContact()
{
}

#include"HaiXanh.h"
#include"Weapon.h"
#include"Player.h"



void HaiXanh ::onAABB(MovableRect* other)
{
	Item::onAABB(other);
	if (other == Player::getInstance() && getItemState() == ITEM_STATE_VISIBLE) {

		setState(ITEM_STATE_PLAYER_EATED);
		this->onPlayerContact();
	}
}

HaiXanh ::HaiXanh ()
{
}

HaiXanh ::~HaiXanh ()
{
}

void HaiXanh ::onPlayerContact()
{
}

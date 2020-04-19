#include"HaiDo.h"
#include"Weapon.h"
#include"Player.h"



void HaiDo::onAABB(MovableRect* other)
{
	Item::onAABB(other);
	if (other == Player::getInstance() && getItemState() == ITEM_STATE_VISIBLE) {

		setState(ITEM_STATE_PLAYER_EATED);
		this->onPlayerContact();
	}
}

HaiDo::HaiDo()
{
}

HaiDo ::~HaiDo()
{
}

void HaiDo::onPlayerContact()
{
}

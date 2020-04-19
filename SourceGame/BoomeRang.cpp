#include"BoomeRang.h"
#include"Weapon.h"
#include"Player.h"



void BoomeRang::onAABB(MovableRect* other)
{
	Item::onAABB(other);
	if (other == Player::getInstance() && getItemState() == ITEM_STATE_VISIBLE) {

		setState(ITEM_STATE_PLAYER_EATED);
		this->onPlayerContact();
	}
}

BoomeRang::BoomeRang()
{
}

BoomeRang ::~BoomeRang()
{
}

void BoomeRang::onPlayerContact()
{
}

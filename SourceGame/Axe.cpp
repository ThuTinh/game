#include"Axe.h"
#include"Weapon.h"
#include"Player.h"



void Axe::onAABB(MovableRect* other)
{
	Item::onAABB(other);
	if (other == Player::getInstance() && getItemState() == ITEM_STATE_VISIBLE) {

		setState(ITEM_STATE_PLAYER_EATED);
		this->onPlayerContact();
	}
}

Axe::Axe()
{
}

Axe ::~Axe()
{
}

void Axe::onPlayerContact()
{
}

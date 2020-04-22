#include"BluePotion.h"
#include"Weapon.h"
#include"Player.h"



void BluePotion::onAABB(MovableRect* other)
{
	Item::onAABB(other);
	if (other == Player::getInstance() && getItemState() == ITEM_STATE_VISIBLE) {

		setState(ITEM_STATE_PLAYER_EATED);
		this->onPlayerContact();
	}
}

BluePotion::BluePotion()
{
}

BluePotion ::~BluePotion()
{
}

void BluePotion::onPlayerContact()
{
}

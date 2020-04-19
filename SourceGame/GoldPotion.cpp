#include"GoldPotion.h"
#include"Weapon.h"
#include"Player.h"



void GoldPotion::onAABB(MovableRect* other)
{
	Item::onAABB(other);
	if (other == Player::getInstance() && getItemState() == ITEM_STATE_VISIBLE) {

		setState(ITEM_STATE_PLAYER_EATED);
		this->onPlayerContact();
	}
}

GoldPotion::GoldPotion()
{
}

GoldPotion ::~GoldPotion()
{
}

void GoldPotion::onPlayerContact()
{
}

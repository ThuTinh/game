#include"Sword.h"
#include"Weapon.h"
#include"Player.h"



void Sword::onAABB(MovableRect* other)
{
	Item::onAABB(other);
	if (other == Player::getInstance() && getItemState() == ITEM_STATE_VISIBLE) {
		
		setState(ITEM_STATE_PLAYER_EATED);
		this->onPlayerContact();
	}
}

Sword::Sword()
{
	setIsRender(false);
}

Sword::~Sword()
{
}
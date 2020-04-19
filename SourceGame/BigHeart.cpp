#include"BigHeart.h"
#include"Weapon.h"
#include"Player.h"



void BigHeart::onAABB(MovableRect* other)
{
	Item::onAABB(other);
	if (other == Player::getInstance() && getItemState() == ITEM_STATE_VISIBLE) {

		setState(ITEM_STATE_PLAYER_EATED);
		this->onPlayerContact();
	}
}

BigHeart::BigHeart()
{
}

BigHeart::~BigHeart()
{
}

void BigHeart::onPlayerContact()
{
}

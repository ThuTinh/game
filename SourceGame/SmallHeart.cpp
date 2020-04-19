#include"SmallHeart.h"
#include"Weapon.h"
#include"Player.h"



void SmallHeart::onAABB(MovableRect* other)
{
	Item::onAABB(other);
	if (other == Player::getInstance() && getItemState() == ITEM_STATE_VISIBLE) {

		setState(ITEM_STATE_PLAYER_EATED);
		this->onPlayerContact();
	}
}

SmallHeart::SmallHeart()
{
}

SmallHeart::~SmallHeart()
{
}

void SmallHeart::onPlayerContact()
{
}

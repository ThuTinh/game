#include "Item.h"
#include"Player.h"
#include"Weapon.h"

extern int getRandom(int start, int end);

void Item::onAABB(MovableRect* other)
{
	if (itemState == ITEM_STATE_PLAYER_EATED)
	{
		return;
	}
	if (other == Weapon::getInstance()) {
		setState(ITEM_STATE_VISIBLE);
		setWidth(this->getSprite()->image->Width);
		setHeight(this->getSprite()->image->Height);
	}
	
}

void Item::setState(ITEM_STATE itemState)
{
	this->itemState = itemState;
}

ITEM_STATE Item::getItemState()
{
	return itemState;
}


void Item::onPlayerContact()
{
}

void Item::onCollision(MovableRect* other, float collisionTime, int nx, int ny)
{
	if (other->getCollisionType() == COLLISION_TYPE_GROUND)
	{
		/* ngăn chặn di chuyển */
		preventMovementWhenCollision(collisionTime, nx, ny);
		PhysicsObject::onCollision(other, collisionTime, nx, ny);
	}

}


void Item::onUpdate(float dt)
{
	switch (itemState)
	{
	case ITEM_STATE_INVISIBLE:
		setIsRender(false);
		setPhysicsEnable(false);
		break;
	case ITEM_STATE_VISIBLE:
		setIsRender(true);
		setPhysicsEnable(true);
		break;
	case ITEM_STATE_PLAYER_EATED:
		setIsRender(false);
		break;
	default:
		break;
	}
	PhysicsObject::onUpdate(dt);
}

Item::Item()
{
	//setState(ITEM_STATE_INVISIBLE);
	setPhysicsEnable(false);

}


Item::~Item()
{
}


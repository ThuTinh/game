#pragma once
#include "PhysicsObject.h"

enum ITEM_STATE
{
	ITEM_STATE_INVISIBLE,
	ITEM_STATE_VISIBLE,
	ITEM_STATE_PLAYER_EATED,
};

class Item :
	public PhysicsObject
{
	ITEM_STATE itemState;
public:
	void onAABB(MovableRect* other) override;
	void setState(ITEM_STATE itemState);
	virtual void onPlayerContact();
	void onUpdate(float dt) override;

	void onCollision(MovableRect* other, float collisionTime, int nx, int ny) override;

	Item();
	~Item();


};


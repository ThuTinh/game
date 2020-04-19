#pragma once
#include "PhysicsObject.h"
/* lớp Zoombie để hiện thực lớp BaseObject */
class Misc :
	public PhysicsObject
{

public:
	void onCollision(MovableRect* other, float collisionTime, int nx, int ny) override;
	void onAABB(MovableRect* other) override;
	void onUpdate(float dt) override;
	void update(float dt) override;
	Misc();
	~Misc();
};


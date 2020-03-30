#pragma once
#include "PhysicsObject.h"
class Enemy : public PhysicsObject
{
public:
	void onCollision(MovableRect* other, float collisionTime, int nx, int ny) override;
	void onUpdate(float dt) override;
	Enemy();
	~Enemy();

private:

};


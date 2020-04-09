#pragma once
#include "PhysicsObject.h"
class Enemy : public PhysicsObject
{
public:
	void onCollision(MovableRect* other, float collisionTime, int nx, int ny) override;
	void onUpdate(float dt) override;
	void onAABB(MovableRect* other) override;
	void setDirectionFollowPlayer();
	Enemy();
	~Enemy();
protected:
	bool isContactGround;
private:

};


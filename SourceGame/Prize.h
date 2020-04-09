#pragma once
#include"PhysicsObject.h"
class Prize : public PhysicsObject
{

public:
	void onCollision(MovableRect* other, float collisionTime, int nx, int ny) override;
	void onUpdate(float dt) override;
	Prize();
	~Prize();

private:

};


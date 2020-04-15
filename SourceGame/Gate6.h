#pragma once
#include "BaseObject.h"

class Gate6 : public BaseObject
{
	//void onAABB(MovableRect* other) override;
	bool checkOnlyOne ;
	
	void onUpdate(float dt) override;
	//void onCollision(MovableRect* other, float collisionTime, int nx, int ny) override;

public:
	Gate6();
	~Gate6();
};


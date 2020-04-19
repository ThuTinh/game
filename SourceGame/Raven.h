#pragma once
#include "Enemy.h"
#include"Player.h"

enum RAVEN_STATE {
	RAVEN_STATE_STAND,
	RAVEN_STATE_ATTACK
};
enum RAVEN_ACTION {
	RAVEN_ACTION_STAND,
	RAVEN_ACTION_ATTACK
};


class Raven : public Enemy
{

public:
	void onCollision(MovableRect* other, float collisionTime, int nx, int ny) override;
	void onUpdate(float dt) override;
	Raven();
	~Raven();
};


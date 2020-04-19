#pragma once
#include "Enemy.h"
#include"Player.h"

enum BAT_ACTION {
	BAT_ACTION_STAND,
	BAT_ACTION_FLY
};
enum BAT_SATE {
	BAT_STATE_STAND,
	BAT_STATE_FLY
};
class Bat : public Enemy
{
	BAT_SATE batState;
public:
	void onCollision(MovableRect* other, float collisionTime, int nx, int ny) override;
	void onUpdate(float dt) override;
	Bat();
	~Bat();
};


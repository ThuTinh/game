#pragma once
#include "Enemy.h"
#include"Player.h"

enum SKETON_STATE {
	SKETON_STATE_STAND,
	SKETON_STATE_ATTACK
};
enum SKETON_ACTION {
	SKETON_ACTION_STAND,
	SKETON_ACTION_ATTACK
};

class Sketon : public Enemy
{

public:
	void onCollision(MovableRect* other, float collisionTime, int nx, int ny) override;
	void onUpdate(float dt) override;
	Sketon();
	~Sketon();
};


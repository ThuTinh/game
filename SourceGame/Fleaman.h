#pragma once
#include "Enemy.h"
#include"Player.h"

enum FLEAMAN_STATE {
	FLEAMAN_STATE_STAND,
	FLEAMAN_STATE_ATTACK
};
enum FLEAMAN_ACTION {
	FLEAMAN_ACTION_STAND,
	FLEAMAN_ACTION_ATTACK
};

class Fleaman : public Enemy
{

public:
	void onCollision(MovableRect* other, float collisionTime, int nx, int ny) override;
	void onUpdate(float dt) override;
	Fleaman();
	~Fleaman();
};


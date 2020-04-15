#pragma once
#include "Enemy.h"
#include"Player.h"

class Fleaman : public Enemy
{

public:
	void onCollision(MovableRect* other, float collisionTime, int nx, int ny) override;
	void onUpdate(float dt) override;
	Fleaman();
	~Fleaman();
};


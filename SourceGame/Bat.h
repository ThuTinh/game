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

public:
	void onUpdate(float dt) override;
	Bat();
	~Bat();
};


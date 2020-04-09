#pragma once
#include"Enemy.h"
#include "GameTexture.h"
enum LEOPART_ACTION
{
	LEOPART_LIE,
	LEOPART_RUN,
	LEOPART_JUMB,
};

enum LEOPART_STATE
{
	LEOPART_STATE_LIE,
	LEOPART_STATE_RUN,
	LEOPART_STATE_JUMP
};

class Leopart : public Enemy
{
	LEOPART_STATE leopartState;
public:
	void onUpdate(float dt) override;
	void onCollision(MovableRect* other, float collisionTime, int nx, int ny) override;
	Leopart();
	~Leopart();

private:

};
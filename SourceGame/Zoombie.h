#pragma once
#include "Enemy.h"
/* lớp Zoombie để hiện thực lớp BaseObject */

enum ZOOMBIE_STATE
{
	ZOOMBIE_STAND,
	ZOOMBIE_RUN,
	ZOOMBIE_RUN_TURNING

};
class Zoombie : public Enemy
{
	ZOOMBIE_STATE zoombieState;
	
public:
	ZOOMBIE_STATE getZoombieState();
	void setZoombieState(ZOOMBIE_STATE zoombiState);
	void onUpdate(float dt) override;
	void onCollision(MovableRect* other, float collisionTime, int nx, int ny) override;
	Zoombie();
	~Zoombie();
};


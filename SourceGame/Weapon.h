#pragma once
#include "PhysicsObject.h"
#include "SpriteManager.h"
#include "KEY.h"
#include "Camera.h"
enum LIST_WEAPON {

	W11,
	W12,
	W13,
	W21,
	W22,
	W23,
	W31,
	W32,
	W33,
	W41,
	W42,
	W43,
};

class Weapon : public PhysicsObject
{
public:
	void render();
	static Weapon* getInstance();
	void onCollision(MovableRect* other, float collisionTime, int nx, int ny) override;
	void onUpdate(float dt) override;

	Weapon();
	~Weapon();

private:
	static Weapon* instance;

};


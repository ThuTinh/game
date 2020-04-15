#include"Sketon.h"
#include"Weapon.h"
#include"Player.h"
#include"Camera.h"
#include "GameConfiguration.h"

void Sketon::onCollision(MovableRect* other, float collisionTime, int nx, int ny)
{
	
	Enemy::onCollision(other, collisionTime, nx, ny);
}

void Sketon::onUpdate(float dt)
{

	Enemy::onUpdate(dt);
}

Sketon::Sketon()
{
	
}

Sketon::~Sketon()
{
}

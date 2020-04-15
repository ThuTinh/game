#include"Fleaman.h"
#include"Weapon.h"
#include"Player.h"
#include"Camera.h"
#include "GameConfiguration.h"

void Fleaman::onCollision(MovableRect* other, float collisionTime, int nx, int ny)
{

	Enemy::onCollision(other, collisionTime, nx, ny);
}

void Fleaman::onUpdate(float dt)
{

	Enemy::onUpdate(dt);
}

Fleaman::Fleaman()
{

}

Fleaman::~Fleaman()
{
}

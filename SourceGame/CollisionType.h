#pragma once
enum COLLISION_TYPE
{
	COLLISION_TYPE_GROUND,
	COLLISION_TYPE_ENEMY,
	COLLISION_TYPE_STAIR,
	/* thêm các collisionType khác trong tool vào đây */

	COLLISION_TYPE_PLAYER,
	/* số lượng collisionType luôn nằm cuối */
	COLLISION_TYPE_COUNT
};
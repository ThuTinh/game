#include "Weapon.h"
#include "Player.h"
#include "Camera.h"

Weapon* Weapon::instance = 0;

Weapon* Weapon::getInstance() {
	if (instance == 0) {
		instance = new Weapon();
	}
	return instance;

}

void Weapon::onCollision(MovableRect* other, float collisionTime, int nx, int ny)
{

	if (other->getCollisionType() == COLLISION_TYPE_MISC) {
		int i = 6;
	}
}

void Weapon::onUpdate(float dt)
{

}

 void Weapon::render()
{

	/* setDirection(TEXTURE_DIRECTION::TEXTURE_DIRECTION_LEFT);*/
	 //if (Player::getInstance()->getIsAttack()){
	 if (Player::getInstance()->getAnimation() == PLAYER_ACTION_STAND_USE_SUB || Player::getInstance()->getAnimation() == PLAYER_ACTION_DUCKING_USE_SUB) {
		 if (Player::getInstance()->getDirection() == TEXTURE_DIRECTION_RIGHT) {
			 setDirection(TEXTURE_DIRECTION::TEXTURE_DIRECTION_LEFT);
			 switch (Player::getInstance()->getFrameAnimation())
			 {
			 case 0:
				 setY(Player::getInstance()->getY() + 2);
				 setX(Player::getInstance()->getX() + 22);
				 setAnimation(W21);
				 setFrameAnimation(0);
				 break;
			 case 1:
				 setY(Player::getInstance()->getY() + 3);
				 setX(Player::getInstance()->getX() + 15);
				 setAnimation(W22);
				 setFrameAnimation(0);
				 break;
			 default:
				 setY(Player::getInstance()->getY() + 2);
				 setX(Player::getInstance()->getX() - 24);
				 setAnimation(W23);
				 setFrameAnimation(0);

				 break;
			 };


		 }
		 else
		 {
			 setDirection(TEXTURE_DIRECTION::TEXTURE_DIRECTION_RIGHT);
			 switch (Player::getInstance()->getFrameAnimation())
			 {
			 case 0:
				 setY(Player::getInstance()->getY());
				 setX(Player::getInstance()->getX() - 32);
				 setAnimation(W21);
				 setFrameAnimation(0);
				
		
				 break;

			 case 1:
				 setY(Player::getInstance()->getY());
				 setX(Player::getInstance()->getX() - 30);
				 setAnimation(W22);
				 setFrameAnimation(0);
			
				 break;
			 default:
				 setY(Player::getInstance()->getY() + 2);
				 setX(Player::getInstance()->getX() + 10);
				 setAnimation(W23);
				 setFrameAnimation(0);
				
				 
			
				break;

			 };
		 }
		 BaseObject::render(Camera::getInstance());
	 }
	/* else
	 {
		 if (Player::getInstance()->getAnimation() == PLAYER_ACTION_DUCKING_USE_SUB) {
			 if (Player::getInstance()->getDirection() == TEXTURE_DIRECTION_RIGHT) {
				 setDirection(TEXTURE_DIRECTION::TEXTURE_DIRECTION_LEFT);
				 switch (Player::getInstance()->getFrameAnimation())
				 {
				 
				 case 0:
					 setY(Player::getInstance()->getY() + 2);
					 setX(Player::getInstance()->getX() + 22);
					 setAnimation(W21);
					 setFrameAnimation(0);
					 break;
				 case 1:
					 setY(Player::getInstance()->getY() + 3);
					 setX(Player::getInstance()->getX() + 15);
					 setAnimation(W22);
					 setFrameAnimation(0);
					 break;
				 default:
					 setY(Player::getInstance()->getY() + 2);
					 setX(Player::getInstance()->getX() - 24);
					 setAnimation(W23);
					 setFrameAnimation(0);

					 break;
				 
				 };


			 }
			 else
			 {
				 setDirection(TEXTURE_DIRECTION::TEXTURE_DIRECTION_RIGHT);
				 switch (Player::getInstance()->getFrameAnimation())
				 {
				 case 0:
					 setY(Player::getInstance()->getY());
					 setX(Player::getInstance()->getX() - 32);
					 setAnimation(W21);
					 setFrameAnimation(0);


					 break;

				 case 1:
					 setY(Player::getInstance()->getY());
					 setX(Player::getInstance()->getX() - 30);
					 setAnimation(W22);
					 setFrameAnimation(0);

					 break;
				 default:
					 setY(Player::getInstance()->getY() + 2);
					 setX(Player::getInstance()->getX() + 10);
					 setAnimation(W23);
					 setFrameAnimation(0);



					 break;

				 };
			 }
			 BaseObject::render(Camera::getInstance());
		 }

	 }*/
			 
	// }
}

 Weapon::Weapon()
 {
	 setSprite(SPR(SPRITE_INFO_WEAPON));
	 setCollisionType(COLLISION_TYPE_WEAPON);

 }

 Weapon::~Weapon()
 {
 }
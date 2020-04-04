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

 void Weapon::render()
{

	/* setDirection(TEXTURE_DIRECTION::TEXTURE_DIRECTION_LEFT);*/
	 //if (Player::getInstance()->getIsAttack()){
	 if (Player::getInstance()->getAnimation() == PLAYER_ACTION_STAND_USE_SUB) {
		 if (Player::getInstance()->getDirection() == TEXTURE_DIRECTION_RIGHT) {
			 setDirection(TEXTURE_DIRECTION::TEXTURE_DIRECTION_LEFT);
			 switch (Player::getInstance()->getFrameAnimation())
			 {
			 case 0:
				 setY(Player::getInstance()->getY() + 2);
				 setX(Player::getInstance()->getX() + 22);
				 setAnimation(W11);
				 setFrameAnimation(0);
				 break;
			 case 1:
				 setY(Player::getInstance()->getY() + 3);
				 setX(Player::getInstance()->getX() + 15);
				 setAnimation(W12);
				 setFrameAnimation(0);
				 break;
			 default:
				 setY(Player::getInstance()->getY() + 2);
				 setX(Player::getInstance()->getX() - 24);
				 setAnimation(W13);
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
				 setX(Player::getInstance()->getX() - 5);
				 setAnimation(W11);
				 setFrameAnimation(0);
				 break;

			 case 1:
				 setY(Player::getInstance()->getY());
				 setX(Player::getInstance()->getX() - 1);
				 setAnimation(W12);
				 setFrameAnimation(0);
				 break;
			 default:
				 setY(Player::getInstance()->getY() + 2);
				 setX(Player::getInstance()->getX() + 40);
				 setAnimation(W13);
				 setFrameAnimation(0);
				 break;

			 };
		 }
		 BaseObject::render(Camera::getInstance());
	 }
			 
	// }
}

 Weapon::Weapon()
 {
	 setSprite(SPR(SPRITE_INFOR_WEAPON));

 }

 Weapon::~Weapon()
 {
 }
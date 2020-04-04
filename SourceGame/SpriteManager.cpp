#include "SpriteManager.h"
SpriteManager * SpriteManager::instance = 0;
SpriteManager * SpriteManager::getInstance()
{
	if (instance == 0)
	{
		instance = new SpriteManager();
	}
	return instance;
}
Sprite * SpriteManager::getSprite(int spriteInfo)
{
	return getInstance()->sprites[spriteInfo];
}
SpriteManager::SpriteManager()
{
	/* thêm SPRITE_COUNT phần tử cho list sprite */
	for (size_t i = 0; i < SPRITE_COUNT; i++)
	{
			sprites._Add(new Sprite());
	}

	/* thêm sprite ở đây */

	
	sprites[SPRITE_INFO_FRIE]->InitFromFile("assets/sprites/misc/fire/image.png", "assets/sprites/misc/fire/fire.info.dat");
	sprites[SPRITE_INFO_LIGHT]->InitFromFile("assets/sprites/misc/light/image.png", "assets/sprites/misc/light/light.info.dat");
	sprites[SPRITE_INFOR_ZOOMBIE]->InitFromFile("assets/sprites/enemy/zoombi/image.png","assets/sprites/enemy/zoombi/zoombi.info.dat");
	sprites[SPRITE_INFO_LEOPART]->InitFromFile("assets/sprites/enemy/leopart/image.png", "assets/sprites/enemy/leopart/leopart.info.dat");
	/* đăng ký sprite cho simon */
	sprites[SPRITE_INFO_SIMON]->InitFromFile("assets/sprites/simon/simon/simon.png", "assets/sprites/simon/simon/simon.info.dat");
	sprites[SPRITE_INFO_SIMON]->image->direction = TEXTURE_DIRECTION_RIGHT;
	sprites[SPRITE_INFOR_WEAPON]->InitFromFile("assets/sprites/weopon/image.png", "assets/sprites/weopon/weapon.info.dat");

}
SpriteManager::~SpriteManager()
{
}

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


	//misc
	sprites[SPRITE_INFO_FRIE]->InitFromFile("assets/sprites/misc/fire/image.png", "assets/sprites/misc/fire/fire.info.dat");
	sprites[SPRITE_INFO_LIGHT]->InitFromFile("assets/sprites/misc/light/image.png", "assets/sprites/misc/light/light.info.dat");
	sprites[SPRITE_INFO_ARCHERY]->InitFromFile("assets/sprites/misc/cung/image.png", "assets/sprites/misc/cung/cung.info.dat");
	sprites[SPRITE_INFO_TYM]->InitFromFile("assets/sprites/misc/tim/image.png", "assets/sprites/misc/tim/tim.info.dat");
	sprites[SPRITE_INFO_SWORD]->InitFromFile("assets/sprites/misc/kiem/image.png", "assets/sprites/misc/kiem/kiem.info.dat");

	/* simon */
	sprites[SPRITE_INFO_SIMON]->InitFromFile("assets/sprites/simon/simon/simon.png", "assets/sprites/simon/simon/simon.info.dat");
	sprites[SPRITE_INFO_SIMON]->image->direction = TEXTURE_DIRECTION_RIGHT;

	//waepon 
	sprites[SPRITE_INFO_WEAPON]->InitFromFile("assets/sprites/weopon/image.png", "assets/sprites/weopon/weapon.info.dat");
	//enemy
	sprites[SPRINTE_INFO_BLACK_NIGHT]->InitFromFile("assets/sprites/enemy/blacknight/image.png", "assets/sprites/enemy/blacknight/blacknight.info.dat");
	sprites[SPRINTE_INFO_BAT]->InitFromFile("assets/sprites/enemy/bat/bat.png", "assets/sprites/enemy/bat/bat.info.dat");
	sprites[SPRITE_INFO_ZOOMBIE]->InitFromFile("assets/sprites/enemy/zoombi/image.png", "assets/sprites/enemy/zoombi/zoombi.info.dat");
	sprites[SPRITE_INFO_LEOPART]->InitFromFile("assets/sprites/enemy/leopart/image.png", "assets/sprites/enemy/leopart/leopart.info.dat");
	sprites[SPRITE_INFO_SKETON]->InitFromFile("assets/sprites/enemy/sketon/image.png", "assets/sprites/enemy/sketon/sketon.info.dat" );
	sprites[SPRITE_INFO_FLEAMAN]->InitFromFile("assets/sprites/enemy/fleaman/image.png", "assets/sprites/enemy/fleaman/fleaman.info.dat");
	sprites[SPRITE_INFO_RAVEN]->InitFromFile("assets/sprites/enemy/raven/image.png", "assets/sprites/enemy/raven/raven.info.dat");

	//sprites[SPRITE_INFO_MISC]->InitFromFile("assets/sprites/misc/scorebar/misc.png", "assets/sprites/misc/scorebar/misc.info.txt");
//	sprites[SPRITE_INFO_MISC]->image->direction = TEXTURE_DIRECTION::TEXTURE_DIRECTION_RIGHT;
}
SpriteManager::~SpriteManager()
{
}

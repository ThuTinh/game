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

	/* đăng ký sprite cho con zoombie */
	sprites[SPRITE_INFO_ZOOMBIE]->InitFromFile("test/zoombie/image.png", "test/zoombie/zoombie.info.dat");
	/* đăng ký sprite cho simon */
	sprites[SPRITE_INFO_SIMON]->InitFromFile("assets/sprites/simon/image.png", "assets/sprites/simon/simon.info.dat");
	sprites[SPRITE_INFO_SIMON]->image->direction = TEXTURE_DIRECTION_RIGHT;

}
SpriteManager::~SpriteManager()
{
}

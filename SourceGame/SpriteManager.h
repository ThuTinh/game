#pragma once

/* sử dụng list */
#include"List.h"
#include"Sprite.h"

/* khai báo 1 define viết tắt cho chữ SpriteManager::getSprite */
#define SPR SpriteManager::getSprite

/* ta tạo 1 sprite info để lưu thông tin của các sprite */
enum SPRITE_INFO
{
	/* đối tượng không có hình ảnh ta sẽ đặt số âm */
	SPRITE_INFO_GATE1 = -3,
	SPRITE_INFO_STAIR = -2,
	SPRITE_INFO_GROUND = -1,

	/* đối tượng có hình ảnh ta sẽ đặt số dương */
	SPRITE_INFO_SIMON = 0,
	SPRITE_INFO_FRIE = 1,
	SPRITE_INFO_LIGHT = 2,
	SPRITE_INFO_LEOPART = 3,
	SPRITE_INFO_ZOOMBIE = 4,
	SPRITE_INFO_TYM = 5,
	SPRITE_INFO_ARCHERY = 6,
	SPRITE_INFO_SWORD = 7,
	SPRITE_INFO_WEAPON = 8,

	SPRITE_COUNT
};

class SpriteManager
{
	/* ta lưu tất cả sprite ở đây */
	List<Sprite*> sprites;

	/* singleton pattern */
	static SpriteManager* instance;
public:
	static SpriteManager* getInstance();

	/* dùng để lấy sprite từ spriteManager */
	static Sprite* getSprite(int spriteInfo);

	SpriteManager();
	~SpriteManager();
};


#pragma once
#include"GameTexture.h"
#include"List.h"
#include"GameTime.h"
#include"FrameAnimation.h"
#include"Animation.h"
#include"Sprite.h"
#include"Scene.h"
#include "SceneManager.h"
class Game
{
	/* singleton pattern */
	static Game* instance;

	/*Scene* world;*/
	SceneManager* sceneManager;

public:
	static Game* getInstance();
	/* Các câu lệnh khởi tạo game */
	void GameInit();
	/* Các câu lệnh cập nhật game */
	void GameUpdate(float dt);
	/* Các câu lệnh vẽ của game */
	void GameRender();
	Game();
	~Game();
};


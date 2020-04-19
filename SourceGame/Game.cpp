#include "Game.h"
#include"KEY.h"
#include"ScoreBar.h"

Game * Game::instance = 0;
Game * Game::getInstance()
{
	if (instance == 0)
		instance = new Game();
	return instance;
}

/* Các câu lệnh khởi tạo game */
void Game::GameInit()
{

	//LevelManager
	sceneManager = new SceneManager();
	sceneManager->init();

	Camera::getInstance()->setSize(
		/* kích thước của camera bằng với kích thước của backbuffer */
		GLOBALS_D("backbuffer_width"), 
		GLOBALS_D("backbuffer_height"));
}
/* Các câu lệnh cập nhật game */
void Game::GameUpdate(float dt)
{
	KEY* key = KEY::getInstance();
	/* cập nhật key */
	key->update();

	/* cập nhật đối tượng trong world */
	sceneManager->getCurrentScene()->update(dt);
	ScoreBar::getInstance()->update();
}
/* Các câu lệnh vẽ của game */
void Game::GameRender()
{
	/* vẽ đối tượng trong world */
	sceneManager->getCurrentScene()->render();
	ScoreBar::getInstance()->render();
}

SceneManager* Game::getSceneManager()
{
	return sceneManager;
}

Game::Game()
{
}


Game::~Game()
{
}

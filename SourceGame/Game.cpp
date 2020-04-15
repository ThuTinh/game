#include "Game.h"
#include"KEY.h"
//#include"ScoreBar.h"

/* singleton pattern */
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
	/* khởi tạo tilemap */
	/*world = new Scene();
	world->Init("assets/levels/level1");*/

	//LevelManager
	levelManager = new LevelManager();
	levelManager->init();

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
	//world->update(dt);

	levelManager->getCurrentLevel()->update(dt);
	//ScoreBar::getInstance()->update();
}
/* Các câu lệnh vẽ của game */
void Game::GameRender()
{
	/* vẽ đối tượng trong world */
	levelManager->getCurrentLevel()->render();
	//ScoreBar::getInstance()->render();
}

LevelManager* Game::getLevelManager()
{
	return levelManager;
}

Game::Game()
{
}


Game::~Game()
{
}

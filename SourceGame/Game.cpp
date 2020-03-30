#include "Game.h"
#include"KEY.h"

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

	//scenemanager
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
	//world->update(dt);

	sceneManager->getCurrentScene()->update(dt);
}
/* Các câu lệnh vẽ của game */
void Game::GameRender()
{
	/* vẽ đối tượng trong world */
	/*world->render();*/
	sceneManager->getCurrentScene()->render();
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

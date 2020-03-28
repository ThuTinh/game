#pragma once
#include "Scene.h"
#include"GameUtils.h"

class SceneManager
{
public:
	int sceneIndex;
	Scene* getCurrentScene();
	void init();
	Scene* nextScene();
	SceneManager();
	~SceneManager();

private:
	Scene** scene;
	int totalScenes;
	
};

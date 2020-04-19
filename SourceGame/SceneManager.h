#pragma once
#include "World.h"
#include"GameUtils.h"
#include"List.h"

class SceneManager
{
public:
	int sceneIndex;
	World* getCurrentScene();
	void init();
	World* nextScene();
	void changeWorld(int index);
	SceneManager();
	~SceneManager();

private:
	World **worlds;
	World* currentScene;
	List<string> listFolderName;
	int totalLeavels;
	
};

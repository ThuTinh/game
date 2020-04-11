#pragma once
#include "World.h"
#include"GameUtils.h"
#include"List.h"

class LevelManager
{
public:
	int levelIndex;
	World* getCurrentLevel();
	void init();
	World* nextLevel();
	void changeScene(int scene);
	LevelManager();
	~LevelManager();

private:
	World *world;
	List<string> listFolderName;
	int totalLeavels;
	
};

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
	void changeWorld(int index);
	LevelManager();
	~LevelManager();

private:
	World **worlds;
	World* currentWorld;
	List<string> listFolderName;
	int totalLeavels;
	
};

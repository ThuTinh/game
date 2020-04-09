#pragma once
#include "World.h"
#include"GameUtils.h"

class LevelManager
{
public:
	int levelIndex;
	World* getCurrentLevel();
	void init();
	World* nextLevel();
	LevelManager();
	~LevelManager();

private:
	World** world;
	int totalLeavels;
	
};

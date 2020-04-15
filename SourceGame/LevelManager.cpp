#include "LevelManager.h"
#include<fstream>
using namespace std;

void LevelManager::init() {
	ifstream fs("assets/scenes/scenes.txt");
	ignoreLineIfstream(fs, 1);
	fs >> levelIndex;
	ignoreLineIfstream(fs, 2);
	fs >> totalLeavels;
	string folderPath;
	ignoreLineIfstream(fs, 2);

	worlds = new World*[totalLeavels];

	for(int i = 0; i<totalLeavels; i++) {
		worlds[i] = new World();
		fs >>  folderPath;;
		listFolderName._Add(folderPath);
		ignoreLineIfstream(fs, 1);		
		worlds[i]->Init(folderPath);
	}

	changeWorld(2);
}
World* LevelManager::getCurrentLevel() {
	return currentWorld;
}

World* LevelManager::nextLevel() {
	if (levelIndex + 1 < totalLeavels) {
		++levelIndex;
	}
	else
	{
		levelIndex = 0;
	}
	return 0;
}

void LevelManager::changeWorld(int index)
{
	this->currentWorld = worlds[index];
	currentWorld->setCurrentScene(0);
	currentWorld->resetLocationInScene();
}

LevelManager::LevelManager() {
		
}
LevelManager::~LevelManager() {

}
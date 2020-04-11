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
	for(int i = 0; i<totalLeavels; i++) {
		fs >>  folderPath;;
		listFolderName._Add(folderPath);
		ignoreLineIfstream(fs, 1);		
	}
	changeScene(1);
}
World* LevelManager::getCurrentLevel() {
	return world;
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

void LevelManager::changeScene(int scene)
{
	delete world;
	if (scene >= totalLeavels || scene<0) {
		scene = 0;
	}
	world = new World();
	world->Init(listFolderName[scene]);
}

LevelManager::LevelManager() {
		
}
LevelManager::~LevelManager() {

}
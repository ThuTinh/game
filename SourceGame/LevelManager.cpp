#include "LevelManager.h"
#include<fstream>
using namespace std;

void LevelManager::init() {
	ifstream fs("assets/scenes/scenes.txt");
	ignoreLineIfstream(fs, 1);
	fs >> levelIndex;
	ignoreLineIfstream(fs, 2);
	fs >> totalLeavels;
	world = new World * [totalLeavels];
	string fileName ;
	ignoreLineIfstream(fs, 2);
	for(int i = 0; i<totalLeavels; i++) {
		fs >> fileName;
		world[i] = new World();
		ifstream f(fileName);
		string folderPath;
		f >> folderPath;
		world[i]->Init(folderPath);
		ignoreLineIfstream(fs, 1);
	}
}
World* LevelManager::getCurrentLevel() {
	return world[levelIndex];
}

World* LevelManager::nextLevel() {
	if (levelIndex + 1 <= totalLeavels) {
		++levelIndex;
	}
	else
	{
		levelIndex = 0;
	}
	return world[levelIndex];
	
}

LevelManager::LevelManager() {
}
LevelManager::~LevelManager() {

}
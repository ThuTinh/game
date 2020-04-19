#include "SceneManager.h"
#include<fstream>
using namespace std;

void SceneManager::init() {
	ifstream fs("assets/scenes/scenes.txt");
	ignoreLineIfstream(fs, 1);
	fs >> sceneIndex;
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

	changeWorld(0);
}
World* SceneManager::getCurrentScene() {
	return currentScene;
}

World* SceneManager::nextScene() {
	if (sceneIndex + 1 < totalLeavels) {
		++sceneIndex;
	}
	else
	{
		sceneIndex = 0;
	}
	return 0;
}

void SceneManager::changeWorld(int index)
{
	this->currentScene = worlds[index];
	currentScene->setCurrentSpace(0);
	currentScene->resetLocationInSpace();
}

SceneManager::SceneManager() {
		
}
SceneManager::~SceneManager() {

}
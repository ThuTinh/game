#include "SceneManager.h"
#include<fstream>
using namespace std;

void SceneManager::init() {
	ifstream fs("assets/scenes/scenes.txt");
	ignoreLineIfstream(fs, 1);
	fs >> sceneIndex;
	ignoreLineIfstream(fs, 2);
	fs >> totalScenes;
	scene = new Scene * [totalScenes];
	string fileName ;
	ignoreLineIfstream(fs, 2);
	for(int i = 0; i<totalScenes; i++) {
		fs >> fileName;
		scene[i] = new Scene();
		ifstream f(fileName);
		string folderPath;
		f >> folderPath;
		scene[i]->Init(folderPath);
		ignoreLineIfstream(fs, 1);
	}
}
Scene* SceneManager::getCurrentScene() {
	return scene[sceneIndex];
}

Scene* SceneManager::nextScene() {
	if (sceneIndex + 1 <= totalScenes) {
		++sceneIndex;
	}
	else
	{
		sceneIndex = 0;
	}
	return scene[sceneIndex];
	
}

SceneManager::SceneManager() {
}
SceneManager::~SceneManager() {

}
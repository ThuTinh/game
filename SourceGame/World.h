#pragma once
#include"Tilemap.h"
#include"SpriteManager.h"
#include"BaseObject.h"
#include"CollisionTypeCollide.h"
#include"Scene.h"
#include "Grid.h"
class World
{
	/* dùng tilemap để vẽ map */
	Tilemap tilemap;
	Grid grid;

	List<BaseObject*> allObjects;
	List<BaseObject*> objectInCamera;

	/* danh sách collisionTypeCollide */
	List<CollisionTypeCollide*> collisionTypeCollides;
	/* danh sách object được phân loại theo collision_type */
	List<List<BaseObject*>*> objectCategories;

	/* danh sách space trong world */
	List<Scene*> scenes;

	/* space hiện tại */
	Scene* currentScene;
	


public:
	/* tất cả object có trong world */

	void Init(const char* tilesheetPath,
		const char* matrixPath, 
		const char* objectsPath,
		const char* collisionTypeCollidePath,
		const char* spacePath);
	void Init(string folderPath);
	
	/* cập nhật các đối tượng trong game */
	void update(float dt);

	void CheckCollisionItem(const size_t& i, float dt, bool& retflag);

	/* setCurrentSpace */
	void setCurrentScene(int sceneIndex);

	Scene* getCurrentScene();

	/* reset camera va player dua vao currentSpace */
	void resetLocationInScene();

	/* vẽ các đối tượng trong game */
	void render();
	World();
	~World();
};


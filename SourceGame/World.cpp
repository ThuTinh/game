#include "World.h"
#include"Camera.h"
#include"Player.h"
#include"Zoombie.h"
#include"KEY.h"
#include"Stair.h"
#include "fire.h"
#include "Gate1.h"
#include "Zoombie.h"
#include "Leopart.h"
#include"Collision.h"
#include "Weapon.h"
#include "Light.h"
#include"Archery.h"
#include"Sword.h"
#include "BigHeart.h"
#include <typeinfo>
#include<Windows.h>
#include <string>


void World::Init(const char * tilesheetPath,
	const char * matrixPath, 
	const char * objectsPath,
	const char* collisionTypeCollidePath, 
	const char * spacePath)
{
	/* khởi tạo vị trí player */
	Player::getInstance()->set(52, 300, 16, 30);
	Weapon::getInstance()->setWidth(25);
	Weapon::getInstance()->setHeight(18);

	/* khởi tạo tilemap */
	tilemap.Init(tilesheetPath, matrixPath);

	int worldHeight = tilemap.getWorldHeight();

	/* khởi tạo phân loại đối tượng */
	for (size_t i = 0; i < COLLISION_TYPE_COUNT; i++)
	{
		objectCategories._Add(new List<BaseObject*>());
	}

	/* khởi tạo đối tượng */
	int objectCount;
	ifstream fs(objectsPath);
	fs >> objectCount;
	for (size_t i = 0; i < objectCount; i++)
	{
		BaseObject* obj;
		int id;
		fs >> id;
		switch (id)
		{
		case SPRITE_INFO_FRIE:
			obj = new Fire();
			break;
		case SPRITE_INFO_LIGHT:
			obj = new Light();
			break;
		case SPRITE_INFO_STAIR:
			obj = new Stair();
			break;
		case SPRITE_INFO_GATE1:
			obj = new Gate1();
			break;
		case SPRITE_INFO_ZOOMBIE:
			obj = new Zoombie();
			break;
		case SPRITE_INFO_LEOPART:
			obj = new Leopart();
			break;
		case SPRITE_INFO_ARCHERY:
			obj = new Archery();
			break;
		case SPRITE_INFO_TYM:
			obj = new BigHeart();
			break;
		case SPRITE_INFO_SWORD:
			obj = new Sword();
			break;
		default:
			obj = new BaseObject();
			break;
		}
		obj->id = id;

		/* đọc thông số của đối tượng */
		obj->onInitFromFile(fs, worldHeight);
		if (id >= 0)
		{
			/* nếu id đối tượng không âm tức đối tượng có sprite ta gán sprite cho nó */
			obj->setSprite(SPR(id));
		}
		/* thêm đối tượng vào danh sách */
	
		allObjects._Add(obj);

		/* thêm object vào từng loại đối tượng */
		objectCategories.at(obj->getCollisionType())->_Add(obj);


	}
	objectCategories.at(Weapon::getInstance()->getCollisionType())->_Add(Weapon::getInstance());


	/* đọc collisiontype collide */
	int numberOfCollisionTypeCollides=0;
	ifstream fsColli(collisionTypeCollidePath);
	fsColli >> numberOfCollisionTypeCollides;
	for (size_t i = 0; i < numberOfCollisionTypeCollides; i++)
	{
		int collisionType1, collisionType2;
		fsColli >> collisionType1 >> collisionType2;
		CollisionTypeCollide* collisionTypeCollide = new CollisionTypeCollide();
		collisionTypeCollide->COLLISION_TYPE_1 = (COLLISION_TYPE)collisionType1;
		collisionTypeCollide->COLLISION_TYPE_2 = (COLLISION_TYPE)collisionType2;
		collisionTypeCollides._Add(collisionTypeCollide); 
	}

	/* đọc space */
	int numberOfScenes = 0;
	ifstream fsScene(spacePath);
	/* enter 1 dòng */
	ignoreLineIfstream(fsScene, 1);
	fsScene >> numberOfScenes;
	for (size_t i = 0; i < numberOfScenes; i++)
	{

		ignoreLineIfstream(fsScene, 4);
		Scene* tempScene = new Scene();
		fsScene >> tempScene->X >> tempScene->Y >> tempScene->Width >> tempScene->Height;


		ignoreLineIfstream(fsScene, 2);
		fsScene >> tempScene->CameraX >> tempScene->CameraY;


		ignoreLineIfstream(fsScene, 2);
		fsScene >> tempScene->PlayerX >> tempScene->PlayerY;

		/* do chiều y của trong file định nghĩa ngược với chiều logic nên cần đổi lại */
		tempScene->CameraY = worldHeight - tempScene->CameraY;
		tempScene->PlayerY = worldHeight - tempScene->PlayerY;
		tempScene->Y = worldHeight - tempScene->Y;
		
		/* thêm vào scene */
		scenes._Add(tempScene);
	}

	/* bắt đầu từ space 0 */
	setCurrentScene(0);
	resetLocationInScene();
}

void World::Init(string folderPath)
{

	/* tìm đường dẫn tilesheet và matrix object */
	string folderPathString = (string)folderPath;
	
	string tilesheetString = folderPathString;
	tilesheetString.append("/tilesheet.png");

	string matrixPathString = folderPathString;
	matrixPathString.append("/matrix.dat");

	string objectPathString = folderPathString;
	objectPathString.append("/objects.dat");

	string collisionTypeCollidePath = folderPathString;
	collisionTypeCollidePath.append("/collision_type_collides.dat");

	string spacePath = folderPathString;
	spacePath.append("/spaces.dat");

	Init(tilesheetString.c_str(), 
		matrixPathString.c_str(), 
		objectPathString.c_str(), 
		collisionTypeCollidePath.c_str(),
		spacePath.c_str());

	string gridPath = folderPathString;
	gridPath.append("/grid.dat");
	grid.Init(gridPath);



}

void World::update(float dt)
{
	
	KEY* key = KEY::getInstance();
	/* cập nhật key */

	/* chuyển space khi nhấn phím */
	//if (key->isSpace1Down)
	//{
	//	setCurrentSpace(0);
	//	resetLocationInSpace();
	//}
	//if (key->isSpace2Down)
	//{
	//	setCurrentSpace(1);
	//	resetLocationInSpace();
	//}
	//if (key->isSpace3Down)
	//{
	//	setCurrentSpace(2);
	//	resetLocationInSpace();
	//}
	//if (key->isSpace4Down)
	//{
	//	setCurrentSpace(3);
	//	resetLocationInSpace();
	//}
	//if (key->isSpace5Down)
	//{
	//	setCurrentSpace(4);
	//	resetLocationInSpace();
	//}

	grid.checkCellColitionCamera(Camera::getInstance());
	List<int> temp = grid.getInxInCamera();

	for (int i = 0; i < objectInCamera.Count; i++)
	{
		auto obj = objectInCamera[i];
		int index = allObjects._IndexOf(obj);
		if (!temp._Contain(index))
		{
			if (!Collision::AABBCheck(Camera::getInstance(), obj))
			{
				objectInCamera._Remove(obj);
				obj->restoreLocation();
				i--;
			}
		}
	}
	
	for (int j = 0; j < temp.Count; j++) {
		int k = temp[j];
		BaseObject* obj = allObjects[k];
		if (obj->getAlive())
		{
			if (!objectInCamera._Contain(obj))
			{
				objectInCamera._Add(obj);
			}
		}
	}



	//cap nhap doi tuong co trong khu vuc cua camera
	for (size_t i = 0; i < objectInCamera.Count; i++)
	{
		OutputDebugStringA(("camara : " + std::to_string(objectInCamera.Count)+ "\n").c_str());
		auto item = objectInCamera.at(i);
		item->update(dt);
		Collision::CheckCollision(Player::getInstance(), item);
		if (Player::getInstance()->getCollitionGate())
		{
			Player::getInstance()->setCollitionGate(false);
			return;

		}
		
	}

	/* cập nhật đối tượng  trong truong hop chua sd grid*/

	//for (size_t i = 0; i < allObjects.Count; i++)
	//{
	//	auto item = allObjects[i];
	//	item->update(dt);
	//	Collision::CheckCollision(Player::getInstance(), item);
	//}


	/* xét va chạm cho các loại đối tượng với nhau */
	for (size_t i = 0; i < collisionTypeCollides.size(); i++)
	{
		
		COLLISION_TYPE col1 = collisionTypeCollides.at(i)->COLLISION_TYPE_1;
		COLLISION_TYPE col2 = collisionTypeCollides.at(i)->COLLISION_TYPE_2;
		/* danh sách đối tượng thuộc collision type 1 */
		List<BaseObject*>* collection1 = objectCategories.at(col1);
		/* danh sách đối tượng thuộc collision type 2 */
		List<BaseObject*>* collection2 = objectCategories.at(col2);

		for (size_t i1 = 0; i1 < collection1->size(); i1++)
		{
			for (size_t i2 = 0; i2 < collection2->size(); i2++)
			{
				/* cho xét va chạm của đối tượng dựa vào 1 cặp collisionType trong CollisionTypeCollide */
				Collision::CheckCollision(collection1->at(i1), collection2->at(i2));
			}
		}
	}

	Player::getInstance()->update(dt);
	Camera::getInstance()->update();
}

void World::setCurrentScene(int sceneIndex)
{
	this->currentScene = scenes.at(sceneIndex);
	Camera::getInstance()->setScene(this->currentScene);
}

Scene * World::getCurrentScene()
{
	return currentScene;
}

void World::resetLocationInScene()
{
	Camera* camera = Camera::getInstance();
	Player* player = Player::getInstance();

	camera->setLocation(getCurrentScene()->CameraX, getCurrentScene()->CameraY);
	player->setLocation(getCurrentScene()->PlayerX, getCurrentScene()->PlayerY);
	//camera->setLocation(0, 400);
	//player->setLocation(0, 300);
}

void World::render()
{
	tilemap.render(Camera::getInstance());

	// vẽ đối tượng xuất  hiện trong camera
	for (size_t i = 0; i < objectInCamera.Count; i++)
	{
		
		//OutputDebugStringA(("Loai gi ne : " + std::to_string(objectInCamera[i].)+ "\n").c_str());
		/* vẽ đối tượng */
			objectInCamera[i]->render(Camera::getInstance());
	}


	Player::getInstance()->render(Camera::getInstance());;
	Weapon::getInstance()->render();
}

World::World()
{
	
}
World::~World()
{
}

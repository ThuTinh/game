#include "World.h"
#include"Camera.h"
#include"Player.h"
#include"Zoombie.h"
#include"KEY.h"
#include"Stair.h"
#include "fire.h"
#include "Gate1.h"
#include"Gate2.h"
#include"Gate3.h"
#include"Gate4.h"
#include"Gate5.h"
#include"Gate6.h"
#include"Gate7.h"
#include "Zoombie.h"
#include "Leopart.h"
#include"BlackNight.h"
#include"Bat.h"
#include"Raven.h"
#include"Fleaman.h"
#include"Sketon.h"
#include"Collision.h"
#include "Weapon.h"
#include "Light.h"
#include"Archery.h"
#include"Sword.h"
#include "BigHeart.h"
#include <typeinfo>
#include<Windows.h>
#include <string>
#include"AdditionalObject.h"

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
		case SPRITE_INFO_GATE2:
			obj = new Gate2();
			break;
		case SPRITE_INFO_GATE3:
			obj = new Gate3();
			break;
		case SPRITE_INFO_GATE4:
			obj = new Gate4();
			break;
		case SPRITE_INFO_GATE5:
			obj = new Gate5();
			break;
		case SPRITE_INFO_GATE6:
			obj = new Gate6();
			break;
		case SPRITE_INFO_GATE7:
			obj = new Gate7();
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
		case SPRINTE_INFO_BLACK_NIGHT:
			obj = new BlackNight();
			break;
		case SPRINTE_INFO_BAT:
			obj = new Bat();
			break;
		case SPRITE_INFO_FLEAMAN:
			obj = new Fleaman();
			break;
		case SPRITE_INFO_SKETON:
			obj = new Sketon();
			break;
		case SPRITE_INFO_RAVEN:
			obj = new Raven();
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
		Space* tempSpace = new Space();
		fsScene >> tempSpace->X >> tempSpace->Y >> tempSpace->Width >> tempSpace->Height;


		ignoreLineIfstream(fsScene, 2);
		fsScene >> tempSpace->CameraX >> tempSpace->CameraY;


		ignoreLineIfstream(fsScene, 2);
		fsScene >> tempSpace->PlayerX >> tempSpace->PlayerY;

		/* do chiều y của trong file định nghĩa ngược với chiều logic nên cần đổi lại */
		tempSpace->CameraY = worldHeight - tempSpace->CameraY;
		tempSpace->PlayerY = worldHeight - tempSpace->PlayerY;
		tempSpace->Y = worldHeight - tempSpace->Y;
		
		/* thêm vào scene */
		spaces._Add(tempSpace);
	}

	/* bắt đầu từ space 0 */
	setCurrentSpace(0);
	resetLocationInSpace();
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
		bool retflag;
		if(objectInCamera.at(i)->getCollisionType() == COLLISION_TYPE::COLLISION_TYPE_GROUND)
		CheckCollisionItem(i, dt, retflag);
	}

	for (size_t i = 0; i < objectInCamera.Count; i++)
	{
		bool retflag;
		if (objectInCamera.at(i)->getCollisionType() != COLLISION_TYPE::COLLISION_TYPE_GROUND)
			CheckCollisionItem(i, dt, retflag);
	}


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

	AdditionalObject::objectsUpdate();
}

void World::CheckCollisionItem(const size_t& i, float dt, bool& retflag)
{
	retflag = true;
	OutputDebugStringA(("camara : " + std::to_string(objectInCamera.Count) + "\n").c_str());
	auto item = objectInCamera.at(i);
	item->update(dt);
	Collision::CheckCollision(Player::getInstance(), item);
	retflag = false;
}

void World::setCurrentSpace(int spaceIndex)
{
	this->currentSpace = spaces.at(spaceIndex);
	Camera::getInstance()->setSpace(this->currentSpace);
}

Space * World::getCurrentSpace()
{
	return currentSpace;
}

void World::resetLocationInSpace()
{
	Camera* camera = Camera::getInstance();
	Player* player = Player::getInstance();
	camera->setLocation(getCurrentSpace()->CameraX, getCurrentSpace()->CameraY);
	player->setLocation(getCurrentSpace()->PlayerX, getCurrentSpace()->PlayerY);

}

void World::render()
{
	tilemap.render(Camera::getInstance());

	// vẽ đối tượng xuất  hiện trong camera
	for (size_t i = 0; i < objectInCamera.Count; i++)
	{
		/* vẽ đối tượng */
			objectInCamera[i]->render(Camera::getInstance());
	}


	Player::getInstance()->render(Camera::getInstance());
	Weapon::getInstance()->render();
	AdditionalObject::objectsRender(Camera::getInstance());

}

World::World()
{
	
}
World::~World()
{
}

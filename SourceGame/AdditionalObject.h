#pragma once
#include "PhysicsObject.h"
#include"SpriteManager.h"
#include"List.h"
class AdditionalObject :
	public PhysicsObject
{
private:
	bool needDelete;
	static List<AdditionalObject*>* objects;
public:
	static List<AdditionalObject*>* getObjects();
	static void objectsUpdate();
	static void objectsRender(Camera* cam);
	virtual void setNeedDelete(bool needDelete);
	void update(float dt);
	AdditionalObject();
	~AdditionalObject();
};


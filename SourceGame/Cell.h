#pragma once
#include "BaseObject.h"
#include "BaseObject.h"
#include "Rect.h"

class Cell : public Rect
{
public:
	//List<BaseObject*>*  getObjects();

	//void SetObjects(List<BaseObject*>* obj);
	List<int> getInxObjects();
	void setInxObjects(List<int> inxList);



	Cell();
	~Cell();

private:

	/*List<BaseObject*>* objList;*/
	List<int> inxObjList;

};


#pragma once
#include "BaseObject.h"
#include "BaseObject.h"
#include "Rect.h"

class Cell : public Rect
{
public:

	List<int> getInxObjects();
	void setInxObjects(List<int> inxList);

	Cell();
	~Cell();

private:

	List<int> inxObjList;

};


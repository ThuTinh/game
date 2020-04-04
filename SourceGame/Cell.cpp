#include"Cell.h"

//List<BaseObject*>* Cell::getObjects() {
//	return objList;
//}

//void Cell::setX(int x)
//{
//	this->x = x;
//}
//
//void Cell::setY(int y)
//{
//	this->y = y;
//}
//
//void Cell::setWith(int with)
//{
//	this->with = with;
//}
//
//int Cell::getX()
//{
//	return x;
//}
//
//int Cell::getY()
//{
//	return y;
//}
//
//int Cell::getWith()
//{
//	return with;
//}
//
//void Cell::SetObjects(List<BaseObject*>* obj)
//{
//	this->objList = obj;
//}

List<int> Cell::getInxObjects()
{
	return inxObjList;
}

void Cell::setInxObjects(List<int> inxList)
{
	inxObjList = inxList;
}

Cell::Cell()
{
	
}

Cell::~Cell()
{
}
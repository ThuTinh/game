#pragma once
#include "BaseObject.h"
class Stair :
	public BaseObject
{
	/* các tham số trong file */
	bool isRightStair, isTop;
public:
	/* override lại phương thức này để đọc các tham số trong file */
	void onInitFromFile(ifstream& fs, int mapHeight) override;
	void setParam(const char* name, bool value);
	/* override lại phương thức onUpdate của baseobject */
	void onUpdate(float dt) override;
	Stair();
	~Stair();
};


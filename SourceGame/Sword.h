#pragma once
#include"Item.h"
class Sword : public Item
{
public:
	void onAABB(MovableRect* other) override;
	Sword();
	~Sword();

private:

};


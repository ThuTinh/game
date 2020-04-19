#pragma once
#include "Item.h"
class SmallHeart : public Item
{
public:
	void onAABB(MovableRect* other) override;
	SmallHeart();
	~SmallHeart();

	void onPlayerContact() override;

private:

};




#pragma once
#include "Item.h"
class BigHeart : public Item
{
public:
	void onAABB(MovableRect* other) override;
	BigHeart();
	~BigHeart();

	void onPlayerContact() override;

private:

};




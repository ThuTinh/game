#pragma once
#include "Item.h"
class Item1000PTS : public Item
{
public:
	void onAABB(MovableRect* other) override;
	Item1000PTS();
	~Item1000PTS();

	void onPlayerContact() override;

private:

};




#pragma once
#include "Item.h"
class Item400PTS : public Item
{
public:
	void onAABB(MovableRect* other) override;
	Item400PTS();
	~Item400PTS();

	void onPlayerContact() override;

private:

};




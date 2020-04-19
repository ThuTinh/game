#pragma once
#include "Item.h"
class Item700PTS : public Item
{
public:
	void onAABB(MovableRect* other) override;
	Item700PTS();
	~Item700PTS();

	void onPlayerContact() override;

private:

};




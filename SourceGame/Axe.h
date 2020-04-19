#pragma once
#include "Item.h"
class Axe : public Item
{
public:
	void onAABB(MovableRect* other) override;
	Axe();
	~Axe();

	void onPlayerContact() override;

private:

};




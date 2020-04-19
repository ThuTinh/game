#pragma once
#include "Item.h"
class GoldPotion : public Item
{
public:
	void onAABB(MovableRect* other) override;
	GoldPotion();
	~GoldPotion();

	void onPlayerContact() override;

private:

};




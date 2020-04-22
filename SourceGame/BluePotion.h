#pragma once
#include "Item.h"
class BluePotion : public Item
{
public:
	void onAABB(MovableRect* other) override;
	BluePotion();
	~BluePotion();

	void onPlayerContact() override;

private:

};




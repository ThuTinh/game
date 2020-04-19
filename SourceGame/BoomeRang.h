#pragma once
#include "Item.h"
class BoomeRang : public Item
{
public:
	void onAABB(MovableRect* other) override;
	BoomeRang();
	~BoomeRang();

	void onPlayerContact() override;

private:

};




#pragma once
#include "Item.h"
class Crown : public Item
{
public:
	void onAABB(MovableRect* other) override;
	Crown();
	~Crown();

	void onPlayerContact() override;

private:

};




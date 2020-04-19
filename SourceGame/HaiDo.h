#pragma once
#include "Item.h"
class HaiDo : public Item
{
public:
	void onAABB(MovableRect* other) override;
	HaiDo();
	~HaiDo();

	void onPlayerContact() override;

private:

};




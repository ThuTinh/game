#pragma once
#include "Item.h"
class HaiXanh  : public Item
{
public:
	void onAABB(MovableRect* other) override;
	HaiXanh ();
	~HaiXanh ();

	void onPlayerContact() override;

private:

};




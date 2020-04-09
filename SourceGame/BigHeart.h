#pragma once
#include "Item.h"
class BigHeart : public Item
{
public:
	BigHeart();
	~BigHeart();

	void onPlayerContact() override;

private:

};




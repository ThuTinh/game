#pragma once
#include"Item.h"
class Archery : public Item
{
public:

	void onAABB(MovableRect* other) override;
	Archery();
	~Archery();

private:

};


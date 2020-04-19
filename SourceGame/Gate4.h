#pragma once
#include "BaseObject.h"

class Gate4 : public BaseObject
{
	void onAABB(MovableRect* other) override;
};


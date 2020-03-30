#pragma once
#include "BaseObject.h"

class Gate1 : public BaseObject
{
	void onAABB(MovableRect* other) override;
};


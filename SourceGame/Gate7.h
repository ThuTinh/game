#pragma once
#include "BaseObject.h"

class Gate7 : public BaseObject
{
	void onAABB(MovableRect* other) override;
};


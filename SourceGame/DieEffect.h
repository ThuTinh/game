#pragma once
#include"AdditionalObject.h"
#include"DelayTime.h"

class DieEffect : public AdditionalObject
{
public:
	DelayTime timeDelay;
	DieEffect();
	void update(float dt);
};
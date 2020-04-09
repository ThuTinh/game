#pragma once
#include "Misc.h"
class Light :
	public Misc
{

public:
	
	Light();
	~Light();
};

Light::Light()
{
	setAnimation(0);
	/*setDirection(TEXTURE_DIRECTION::TEXTURE_DIRECTION_LEFT);*/
}

Light::~Light()
{
}

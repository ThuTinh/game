#pragma once
#include"Enemy.h"
#include "GameTexture.h"
enum LEOPART_ACTION
{
	LEOPART_LIE,
	LEOPART_JUMB,
	LEOPART_RUN

};

class Leopart : public Enemy
{
public:
	Leopart();
	~Leopart();

private:

};

Leopart::Leopart()
{
	setAnimation(0);
	setDirection(TEXTURE_DIRECTION::TEXTURE_DIRECTION_LEFT);
}

Leopart::~Leopart()
{
}

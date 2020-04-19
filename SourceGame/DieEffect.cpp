#include "DieEffect.h"

DieEffect::DieEffect()
{
	timeDelay.init(GLOBALS_D("die_effect_time"));
	setSprite(SpriteManager::getInstance()->getSprite(SPRITE_INFO::SPRITE_INFO_DIE_EFFECT));
}

void DieEffect::update(float dt)
{
	timeDelay.update();
	if (timeDelay.isTerminated())
	{
		setNeedDelete(true);
	}

	AdditionalObject::update(dt);
}

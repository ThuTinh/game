#include "BaseObject.h"
#include "Player.h"
#include "Weapon.h"

void BaseObject::setAlive(bool alive)
{
	this->alive  = alive;
}

bool BaseObject::getAlive()
{
	return alive;
}

void BaseObject::setIsRender(bool isRender)
{
	this->isRender = isRender;
}

bool BaseObject::getisRender()
{
	return isRender;
}

void BaseObject::setSprite(Sprite * sprite)
{
	this->sprite = sprite;
}

Sprite * BaseObject::getSprite()
{
	return this->sprite;
}

bool BaseObject::getPauseAnimation()
{
	return pauseAnimation;
}

void BaseObject::setPauseAnimation(bool pauseAnimation)
{
	this->pauseAnimation = pauseAnimation;
}

bool BaseObject::getIsLastFrameAnimationDone()
{
	return isLastFrameAnimationDone;
}

void BaseObject::setIsLastFrameAnimationDone(bool isLastFrameAnimationDone)
{
	this->isLastFrameAnimationDone = isLastFrameAnimationDone;
}

void BaseObject::onInitFromFile(ifstream& fs, int mapHeight)
{
	int collisionType, x, y, width, height;
	/* đọc collision type x y width height từ file. collision_type thì sẽ học ở bài sau */
	fs >> collisionType >> x >> y >> width >> height;
	/* do y của đối tượng trong file là tọa độ hướng từ trên xuống
	Nhưng y của game chúng ta làm thì gốc tọa độ bên dưới nên ta chuyển nó về cho đúng tọa độ logic */
	y = mapHeight - y;
	/* khởi tạo x y width height cho đối tượng */
	set(x, y, width, height);
	/* khởi tạo collisionType */

	initBox = new Rect();

	initBox->set(x, y, width, height);

	setCollisionType((COLLISION_TYPE)collisionType);
}




void BaseObject::update(float dt)
{
	/* chúng ta di chuyển đối tượng trước khi cập nhật */
	goX();
	goY();

	/* mặc định đây không phải là frame cuối đã hoàn thành */
	setIsLastFrameAnimationDone(false);

	/* nếu đối tượng này có hình và không bị pauseAnimation thì ta cập nhật animation cho nó */
	//if ()
	//{
		if (getSprite()!= NULL && animationGameTime.atTime() && !pauseAnimation)
		{
			/* cập nhật animation cho đối tượng */
			sprite->update(animationIndex, frameIndex);
			if (frameIndex == 0)
			{
				/* nếu frame cuối đã chạy thì sau khi cập nhật frameIndex sẽ là 0 */
				setIsLastFrameAnimationDone(true);
			}
		}	
		onUpdate(dt);
	//}

}

void BaseObject::onUpdate(float dt)
{
	/* mặc định sẽ cho chạy animation */
	setPauseAnimation(false);
}

void BaseObject::render(Camera* camera)
{
	if (!getAlive())
		return;
	if (!getisRender())
		return;
	if (getSprite() == 0)
		return;
	float xView, yView;
	/* tính tọa độ view để vẽ đối tượng lên màn hình */
	camera->convertWorldToView(getX(), getY(), xView, yView);

	/* hướng mặt mặc định của bức hình */
	TEXTURE_DIRECTION imageDirection = sprite->image->direction;

	/* hướng mặt của nhân vật */
	TEXTURE_DIRECTION currentDirection = getDirection();


	/* nếu hướng mặt của nhân vật khác với hướng mặt trong bức hình thì tiến hành lật hình */
	if (imageDirection != currentDirection)
	{
		int currentFrameWidth = getSprite()->animations[getAnimation()]->frames[getFrameAnimation()]->right -
			getSprite()->animations[getAnimation()]->frames[getFrameAnimation()]->left;
		D3DXMATRIX flipMatrix;
		D3DXMatrixIdentity(&flipMatrix);
		flipMatrix._11 = -1;
		flipMatrix._41 = 2 * (xView + currentFrameWidth / 2) - currentFrameWidth + getWidth();
		GameDirectX::getInstance()->GetSprite()->SetTransform(&flipMatrix);
	}

	/* vẽ đối tượng lên màn hình */
	sprite->render(xView, yView, animationIndex, frameIndex);

	if (direction != imageDirection)
	{
		/* khôi phục lại ma trận mặc định */
		D3DXMATRIX identityMatrix;
		D3DXMatrixIdentity(&identityMatrix);
		GameDirectX::getInstance()->GetSprite()->SetTransform(&identityMatrix);
	}
}

void BaseObject::restoreLocation()
{
	set(initBox->getX(), initBox->getY(), initBox->getWidth(), initBox->getHeight());
	setAlive(true);
}

int BaseObject::getAnimation()
{
	return animationIndex;
}

void BaseObject::setAnimation(int animation)
{
	/* nếu set khác animation thì cho chạy lại từ frame 0 */
	if (this->animationIndex != animation)
	{
		setFrameAnimation(0);
	}
	this->animationIndex = animation;
}

int BaseObject::getFrameAnimation()
{
	return frameIndex;
}

void BaseObject::setFrameAnimation(int frameAnimation)
{
	this->frameIndex = frameAnimation;
}

int BaseObject::getFrameIndex()
{
	return frameIndex;
}

TEXTURE_DIRECTION BaseObject::getDirection()
{
	return direction;
}

void BaseObject::setDirection(int direction)
{
	this->direction = (TEXTURE_DIRECTION)direction;
}

BaseObject::BaseObject()
{
	setSprite(NULL);
	animationGameTime.init(GLOBALS_D("object_animation_time_default"));
	setStopCollision(false);
}


BaseObject::~BaseObject()
{
}

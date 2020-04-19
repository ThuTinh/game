#pragma once
#include<Windows.h>
class KEY
{
public:
	bool
		isLeftDown,
		isRightDown,

		isUpDown,
		isPreviousUpDown,
		isUpPress,

		isDownDown,
		isPreviousDownDown,
		isDownPress,

		isJumpDown,
		isPreviousJumpDown,
		isJumpPress,

		isAttackDown,
		isPreviousAttackDown,
		isAttackPress;

	static KEY* instance;
	static KEY* getInstance();


	void update();
	
	KEY();
	~KEY();
};


#pragma once
#include "PhysicsObject.h"
#include"SpriteManager.h"
#include"KEY.h"

enum PLAYER_ACTION
{
	/* animation đầu tiên */
	PLAYER_ACTION_STAND, //0
	/* animation thứ 2 */
	PLAYER_ACTION_RUN, // 1
	/* animation thứ 3 */
	PLAYER_ACTION_JUMP, // 2
	PLAYER_ACTION_GO_STAIR_UP, // 
	PLAYER_ACTION_GO_STAIR_DOWN, // 4
	PLAYER_ACTION_HURT,
	PLAYER_ACTION_DEATH,
	PLAYER_ACTION_INTRO,
	PLAYER_ACTION_STAND_USE_SUB,
	PLAYER_ACTION_DUCKING_USE_SUB,
	PLAYER_ACTION_GO_STAIR_UP_USE_SUB,
	PLAYER_ACTION_GO_STAIR_DOWN_USE_SUB,
	PLAYER_ACTION_COLORS
};

/* các trạng thái của player */
enum PLAYER_STATE
{
	PLAYER_STATE_NORMAL,
	PLAYER_STATE_ON_STAIR,
	PLAYER_STATE_DIE
};

/* các trạng thái của player khi ở stair */
enum PLAYER_STAIR_STATE
{
	PLAYER_STAIR_STATE_NORUN,
	PLAYER_STAIR_STATE_GO_UP,
	PLAYER_STAIR_STATE_GO_DOWN
};

class Player :
	public PhysicsObject
{
	static Player* instance; 

	/* trạng thái của player */
	PLAYER_STATE playerState;

	int stairDirection;

	/* 2 thuộc tính này có khi player đang đi lên cầu thang chủ yếu nói về player đi tới đâu rồi dừng lại */
	int playerStairDestx, playerStairDesty;
	
	PLAYER_STAIR_STATE playerStairState;

	/* là lần di chuyển cuối cùng của player. sau khi di chuyển player sẽ thoát khỏi stair  */
	bool isLastRunStair;

public:

	PLAYER_STATE getPlayerState();
	void setPlayerState(PLAYER_STATE playerState);
	/* phương thức gọi ngay khi gặp stair và người chơi nhấn phím lên xuống để vào stair */
	void setStartStair();

	/* phương thức gọi ngay khi player quyết định thoát khỏi stair */
	void setStopStair();

	bool getIsLastRunStair();
	void setIsLastRunStair(bool isLastRunStair);

	/* đi lên cầu thang */
	void goStairUp();
	void goStairDown();

	static Player* getInstance();
	void onUpdate(float dt) override;
	void onCollision(MovableRect* other, float collisionTime, int nx, int ny) override;

	void setStairDirection(int stairDirection);
	void setPlayerStairState(PLAYER_STAIR_STATE playerStairState);
	PLAYER_STAIR_STATE getPlayerStairState();

	Player();
	~Player();
};


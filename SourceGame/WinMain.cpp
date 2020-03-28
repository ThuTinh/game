#include<Windows.h>
#include"WindowGame.h"
#include"GameDirectX.h"
#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<fstream>
#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

#include"Game.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	WindowGame::getInstance()->initHandleWindows(hInstance, nCmdShow);
	srand(time(NULL));

	/* GetTickCount: lấy thời gian hiện tại của hệ thống */
	/* Tính thời gian bắt đầu */
	DWORD startTime = GetTickCount();

	MSG msg;
	ZeroMemory(&msg, sizeof(msg));

	/* Tính thời gian cho mỗi frame */
	DWORD timePerFrame = 1000 / GLOBALS_D("fps");

	Game::getInstance()->GameInit();

	/* vòng lặp game */
	while (msg.message != WM_QUIT)
	{
		/* now là thời gian hiện tại */
		DWORD now = GetTickCount();
		/* nếu khoảng thời gian kể từ lúc bắt đầu tới bây giờ lớn hơn thời gian cho mỗi frame thì khởi tạo lại thời gian bắt đầu
		là bây giờ*/
		DWORD deltaTime = now - startTime;
		if (deltaTime >= timePerFrame)
		{

			if (deltaTime >= 2 * timePerFrame)
			{
				deltaTime = timePerFrame;
			}

			//40, 40 

			/* time : thời gian giữa 2 frame dùng để tính vận tốc đối tượng */
			float time = deltaTime / 1000.0f;


			// player->x += dx, player->y += dy;
			// tinh dx va dy player co the di : 2, 10; luc nay player-> 
			// va cham
			

			Game::getInstance()->GameUpdate(time);

			// 42, 50

			startTime = now;
			if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			// vi tri hinh player 40, 40. 
			GameDirectX::getInstance()->BeginGraphics();//bat dau ve len backbuffer

			Game::getInstance()->GameRender();

			GameDirectX::getInstance()->EndGraphics();// ket thuc ve len backbuffer
			GameDirectX::getInstance()->PresentBackBuffer();// ve backbuffer len man hinh

			// hinh con player 42, 50
		}

	}
	return nCmdShow;
}

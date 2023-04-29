#pragma once 
#include <iostream>
#include <conio.h>
#include <Windows.h>

#define ANSI_COLOR_RED      "\x1b[31m"
#define ANSI_COLOR_GREEN    "\x1b[32m"
#define ANSI_COLOR_YELLOW   "\x1b[33m"
#define ANSI_COLOR_BLUE     "\x1b[34m"
#define ANSI_COLOR_MAGENTA  "\x1b[35m"
#define ANSI_COLOR_CYAN     "\x1b[36m"
#define ANSI_COLOR_RESET    "\x1b[0m"

#define KEY_ESC 27
#define KEY_LEFT 'a'
#define KEY_RIGHT 'd'
#define KEY_ENTER 13
#define KEY_YES 'y'
#define KEY_NO 'n'




namespace MuSoeun
{
	void gotoxy(int x, int y) {
		//x, y 좌표 설정
		COORD pos = { x,y };
		//커서 이동
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	}

	void SetCursorState(bool visible)
	{
		CONSOLE_CURSOR_INFO consoleCursorInfo;
		consoleCursorInfo.bVisible = visible;
		consoleCursorInfo.dwSize = 1;
		SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &consoleCursorInfo);
	}


	class MGameLoop
	{
	public:
		MGameLoop() {}
		~MGameLoop() {}
		char key_input = 0;

		bool isGameRunning = false;

		void Initialize()
		{
			SetCursorState(false);

			gotoxy(3, 15);
			std::cout << ANSI_COLOR_RESET"게임 초기화중" << std::endl;
			isGameRunning = true;
		}
		void Release()
		{
			gotoxy(3, 18);
			std::cout << ANSI_COLOR_RESET"게임 종료중" << std::endl;
		}
		void Update()
		{
			gotoxy(3, 16);
			std::cout << ANSI_COLOR_RESET"게임 키입력 대기" << std::endl;
			if (_kbhit())
			{
				KeyEvent(_getch());
			}
		}
		void Render()
		{
			gotoxy(3, 17);
			std::cout << ANSI_COLOR_RESET"게임 화면 그리기" << std::endl;
		}

		void Qt()
		{
			gotoxy(8, 8);
			std::cout << ANSI_COLOR_RESET"종료 하시겠습니까? \n\n" << std::endl;
			gotoxy(6, 10);
			std::cout << ANSI_COLOR_RESET" [  예  ]    [아니오] " << std::endl;
			key_input = _getch();
			

		}
		void YEnter()
		{
			if (KEY_ENTER)
			{
				isGameRunning = false;
			}
		}
		void NEnter()
		{
			if (KEY_ENTER)
			{
				isGameRunning = true;
			}
		}

		void Run()
		{
			Initialize();
			while (isGameRunning)
			{
				Update();
				Render();
			}
			Release();
		}

		void KeyEvent(char KeyInput)
		{
			switch (KeyInput)
			{
				/* 한번 ESC누르면 일시 정지가 되고
				 * 여기서 나가기를 선택하면 나가진다			 *
				 */
			case KEY_ESC:
				/*isGameRunning = false;*/
				Qt();
				break;
			case KEY_LEFT:
				gotoxy(5, 5);
				std::cout << ANSI_COLOR_RED"왼쪽 눌림  " << std::endl;
				break;
			case KEY_RIGHT:
				gotoxy(5, 5);
				std::cout << ANSI_COLOR_GREEN"오른쪽 눌림" << std::endl;
				break;
			case KEY_ENTER:
				gotoxy(5, 5);
				std::cout << ANSI_COLOR_BLUE"엔터 눌림  " << std::endl;
				break;
			case KEY_YES:
				gotoxy(5, 10);
				std::cout << ANSI_COLOR_YELLOW"  [  예  ] " << std::endl;
				YEnter();
				break;
			case KEY_NO:
				gotoxy(15, 10);
				std::cout << ANSI_COLOR_YELLOW"    [아니오]" << std::endl;
				NEnter();
				break;
			default:
				isGameRunning = true;
				break;
			}
		}
	};

}

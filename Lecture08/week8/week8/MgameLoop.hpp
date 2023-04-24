/*#define _Is_THIS_HEADER_INCLUDED 같은 의미의 디파인문*/
#pragma once //once : 단 한번만 컴파일 해라
#include <iostream>
#include <conio.h>


namespace Musoeun //게임 루프 만들기
{
	class MGameLoop
	{
	public:

		bool isGameRunning = false;
		MGameLoop() {}
		~MGameLoop() {}

		void Initialize()
		{
			isGameRunning = true;
			std::cout << "초기화 완료" << std::endl;
		}

		void Release()
		{
			std::cout << "시스템 해제 완료" << std::endl;
		}

		void Update()
		{
			std::cout << "업데이트 중  완료" << std::endl;
			if (_kbhit())
			{	
				KeyEvent(_getch());

			}
			/*char a;
			a = getchar();
			if (a == '1')
			{
				isGameRunning = false;
			}*/
		}

		void Render()
		{
			std::cout << "렌더링 완료" << std::endl;
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
		void KeyEvent(char keyInput)
		{
			int a, b;
			switch (keyInput)
			{
			case 'a': //왼쪽 화살표
				a = 0;
				break;
			case 'd'://오른쪽 화살표
				b = 0;
				break;
			case '27':
				//27 : esc키고 게임 종료키 입니다. / 한번 눌렀을 때 일시 정지 / 두번 눌렀을 시 게임종료
				isGameRunning = false;
				//24일 8주차 과제

				std::cout << "정말 게임을 종료 하시겠습니까?" << std::endl;

				break;
			default:
				break;
			}
		}
	};
}
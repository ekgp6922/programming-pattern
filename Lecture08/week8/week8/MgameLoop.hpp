/*#define _Is_THIS_HEADER_INCLUDED ���� �ǹ��� �����ι�*/
#pragma once //once : �� �ѹ��� ������ �ض�
#include <iostream>
#include <conio.h>


namespace Musoeun //���� ���� �����
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
			std::cout << "�ʱ�ȭ �Ϸ�" << std::endl;
		}

		void Release()
		{
			std::cout << "�ý��� ���� �Ϸ�" << std::endl;
		}

		void Update()
		{
			std::cout << "������Ʈ ��  �Ϸ�" << std::endl;
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
			std::cout << "������ �Ϸ�" << std::endl;
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
			case 'a': //���� ȭ��ǥ
				a = 0;
				break;
			case 'd'://������ ȭ��ǥ
				b = 0;
				break;
			case '27':
				//27 : escŰ�� ���� ����Ű �Դϴ�. / �ѹ� ������ �� �Ͻ� ���� / �ι� ������ �� ��������
				isGameRunning = false;
				//24�� 8���� ����

				std::cout << "���� ������ ���� �Ͻðڽ��ϱ�?" << std::endl;

				break;
			default:
				break;
			}
		}
	};
}
/*#define _Is_THIS_HEADER_INCLUDED ���� �ǹ��� �����ι�*/
#pragma once //once : �� �ѹ��� ������ �ض�


namespace Musoeun //���� ���� �����
{
	class MGameLoop
	{
	public : 

		bool isGameRunning = false;
		MGameLoop(){}
		~MGameLoop(){}

		void Initialize()
		{
			isGameRunning = true;
			std:: << "�ʱ�ȭ �Ϸ�" << std::endl;
		}

		void Release()
		{
			std:: << "�ý��� ���� �Ϸ�" << std::endl;
		}

		void Update()
		{
			std:: << "������Ʈ ��  �Ϸ�" << std::endl;

			char a;
			a = getchar();
			if (a=='1')
			{
				isGameRunning = false;
			}
		}

		void Render()
		{
			std:: << "������ �Ϸ�" << std::endl;
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
	};
}
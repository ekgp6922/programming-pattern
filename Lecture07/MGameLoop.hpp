/*#define _Is_THIS_HEADER_INCLUDED 같은 의미의 디파인문*/
#pragma once //once : 단 한번만 컴파일 해라


namespace Musoeun //게임 루프 만들기
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
			std:: << "초기화 완료" << std::endl;
		}

		void Release()
		{
			std:: << "시스템 해제 완료" << std::endl;
		}

		void Update()
		{
			std:: << "업데이트 중  완료" << std::endl;

			char a;
			a = getchar();
			if (a=='1')
			{
				isGameRunning = false;
			}
		}

		void Render()
		{
			std:: << "렌더링 완료" << std::endl;
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
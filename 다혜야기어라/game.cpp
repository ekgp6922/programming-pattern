#include "game.h"
#include <conio.h>

void Object::Render(char* screenBuf) const
{
    // Object의 렌더링 기능 구현
    // screenBuf를 활용하여 Object의 모양을 그린다.
}

Scene::Scene(int w, int h) : width(w), height(h)
{
    Initialize();
}

Scene::~Scene()
{
    ReleaseScreenBuf();
}

void Scene::Initialize()
{
    objList.clear();
    InitScreenBuf();
}

void Scene::InitScreenBuf()
{
    screenBuf = new char[(width + 1) * height + height];
    for (int i = 0; i < height; i++)
    {
        screenBuf[(width + 1) + (width + 1) * i - 1] = '\n';
    }
    screenBuf[(width + 1) + (width + 1) * (height - 1) - 1] = '\0';
}

void Scene::ReleaseScreenBuf()
{
    if (screenBuf != nullptr)
    {
        delete[] screenBuf;
    }
}

void Scene::Draw()
{
    ClearScreenBuf();

    // Active한 Object의 Render 호출
    for (const Object& obj : objList)
    {
        obj.Render(screenBuf);
    }

    // 화면 전체를 출력
    std::cout << screenBuf;
}

void Scene::ClearScreenBuf()
{
    for (int i = 0; i < (width + 1) * height; i++)
    {
        screenBuf[i] = ' ';
    }
}

void Component::Start()
{
    // Start 함수 구현
}

void Component::Update()
{
    // Update 함수 구현
}

void print_title_screen()
{
    std::cout << "****************************************" << std::endl;
    std::cout << "*                                      *" << std::endl;
    std::cout << "*                                      *" << std::endl;
    std::cout << "*             지렁이 게임              *" << std::endl;
    std::cout << "*            (Snake Bite)              *" << std::endl;
    std::cout << "*                                      *" << std::endl;
    std::cout << "*            1. 게임 시작              *" << std::endl;
    std::cout << "*            2. 게임 설명              *" << std::endl;
    std::cout << "*            3. 게임 랭킹 보기         *" << std::endl;
    std::cout << "*            4. 게임 종료 (esc)        *" << std::endl;
    std::cout << "*                                      *" << std::endl;
    std::cout << "****************************************" << std::endl;
}
int introduction_screen()
{
	std::cout << ANSI_COLOR_RESET"******************************************" << std::endl;
	std::cout << ANSI_COLOR_RESET"*         게임 설명화면입니다.           *" << std::endl;
	std::cout << ANSI_COLOR_RESET"*         게임 설명은 안할겁니다.        *" << std::endl;
	std::cout << ANSI_COLOR_RESET"******************************************" << std::endl;
	std::cout << ANSI_COLOR_RESET"*   타이틀화면으로 돌아갈까요? (Y/N)     *" << std::endl;
	std::cout << ANSI_COLOR_RESET"******************************************" << std::endl;
	return 0;
}

void start_game()
{
	int game_state = 0;
	int mod_r = 1;
	bool isYesSelected = true;
	int isgamerunning = 1;
	int width, height;
	std::cout << "게임 화면의 가로 길이를 입력하세요: ";
	std::cin >> width;
	std::cout << "게임 화면의 세로 길이를 입력하세요: ";
	std::cin >> height;

	Scene scene(width, height);

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (i == height / 2 && j >= width / 2 - 1 && j <= width / 2 + 1)
			{
				std::cout << "o";
			}
			else if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
			{
				std::cout << "*";
			}
			else
			{
				std::cout << " ";
			}
		}
		std::cout << std::endl;
	}
	std::cout << "안녕 난 벌레(김다혜)" << std::endl;
}


int main()
{
	int game_state = 0; //게임 스테이지
	int isgamerunning = 1; //게임 종료
	int mod_r = 1; //아무 키를 입력 받지 못하게 하는 코드
	bool isYesSelected = true;


	while (isgamerunning)
	{
		char key_input = 0;
		switch (game_state)
		{
		case 0:
			if (mod_r)
			{
				print_title_screen();
				// scene의 screenBuf에 타이틀 화면 저장
			}

			key_input = _getch();

			mod_r = 0;

			switch (key_input)
			{
			case '1':
				start_game();
				break;
			case '2':
				std::cout << "이 게임은 다혜가 밤세가면서 만들고있는 다혜야 죽어라입니다." << std::endl;
				main();
				break;
			case '3':
				std::cout << "추후 업데이트예정" << std::endl;
				main();
				break;
			case '4':
				if (key_input == '4')
				{
					isYesSelected = true;
					mod_r = 0; //아무 키를 입력 받지 못하게 하는 코드
					//게임 종료
					Gotoxy(5, 100);
					std::cout << ANSI_COLOR_RESET "종료하시겠습니까?" << std::endl;
					Gotoxy(5, 101);
					std::cout << ANSI_COLOR_YELLOW "[예]" << std::endl;
					Gotoxy(15, 101);
					std::cout << ANSI_COLOR_RESET "[아니오]  " << std::endl;

					while (true) // ESC를 눌러서 나갈 때까지 반복한다.
					{
						if (_kbhit()) //키 입력 받기
						{
							char key = _getch();

							if (key == KEY_LEFT || key == KEY_RIGHT) // 'a' 또는 'd'가 입력되면 선택된 메뉴를 변경한다.
							{
								isYesSelected = !isYesSelected;

								// 선택된 메뉴에 따라 노란색 또는 기본 색상으로 출력한다.
								if (isYesSelected)
								{
									Gotoxy(5, 101);
									std::cout << ANSI_COLOR_YELLOW "[예]  ";
									Gotoxy(15, 101);
									std::cout << ANSI_COLOR_RESET "[아니오]  ";
								}
								else
								{
									Gotoxy(5, 101);
									std::cout << ANSI_COLOR_RESET "[예]  ";
									Gotoxy(15, 101);
									std::cout << ANSI_COLOR_YELLOW "[아니오]  ";
								}
							}
							else if (key == KEY_ENTER) // Enter가 입력되면 선택된 메뉴에 따라 종료하거나 게임을 계속 실행한다.
							{
								if (isYesSelected)
								{
									isgamerunning = false;
									break;
								}
								else
								{
									Gotoxy(5, 100);
									std::cout << "                     " << std::endl; //종료 메시지 지우기
									Gotoxy(5, 101);
									std::cout << "     " << std::endl; //선택 메뉴 지우기
									Gotoxy(15, 101);
									std::cout << "        " << std::endl;
									isgamerunning = true;
									break; //반복문 종료
									print_title_screen();
								}
							}
						}
					}
				}
				break;
			case 27:
				if (key_input == KEY_ESC)
				{
					isYesSelected = true;
					mod_r = 0; //아무 키를 입력 받지 못하게 하는 코드
					//게임 종료
					Gotoxy(5, 100);
					std::cout << ANSI_COLOR_RESET "종료하시겠습니까?" << std::endl;
					Gotoxy(5, 101);
					std::cout << ANSI_COLOR_YELLOW "[예]" << std::endl;
					Gotoxy(15, 101);
					std::cout << ANSI_COLOR_RESET "[아니오]  " << std::endl;

					while (true) // ESC를 눌러서 나갈 때까지 반복한다.
					{
						if (_kbhit()) //키 입력 받기
						{
							char key = _getch();

							if (key == KEY_LEFT || key == KEY_RIGHT) // 'a' 또는 'd'가 입력되면 선택된 메뉴를 변경한다.
							{
								isYesSelected = !isYesSelected;

								// 선택된 메뉴에 따라 노란색 또는 기본 색상으로 출력한다.
								if (isYesSelected)
								{
									Gotoxy(5, 101);
									std::cout << ANSI_COLOR_YELLOW "[예]  ";
									Gotoxy(15, 101);
									std::cout << ANSI_COLOR_RESET "[아니오]  ";
								}
								else
								{
									Gotoxy(5, 101);
									std::cout << ANSI_COLOR_RESET "[예]  ";
									Gotoxy(15, 101);
									std::cout << ANSI_COLOR_YELLOW "[아니오]  ";
								}
							}
							else if (key == KEY_ENTER) // Enter가 입력되면 선택된 메뉴에 따라 종료하거나 게임을 계속 실행한다.
							{
								if (isYesSelected)
								{
									isgamerunning = false;
									break;
								}
								else
								{
									Gotoxy(5, 100);
									std::cout << "                     " << std::endl; //종료 메시지 지우기
									Gotoxy(5, 101);
									std::cout << "     " << std::endl; //선택 메뉴 지우기
									Gotoxy(15, 101);
									std::cout << "        " << std::endl;
									isgamerunning = true;
									 //반복문 종료
									std::cout << ANSI_COLOR_RESET "타이틀로 돌아갑니다.\n\n";
									print_title_screen();
									
									break;
								}
							}
						}
					}
				}
				break;
			default:
				break;
			}
			break;
		}
	}return 0;
}
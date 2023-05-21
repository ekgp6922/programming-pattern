#include "game.h"
#include <conio.h>

void Object::Render(char* screenBuf) const
{
    // Object�� ������ ��� ����
    // screenBuf�� Ȱ���Ͽ� Object�� ����� �׸���.
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

    // Active�� Object�� Render ȣ��
    for (const Object& obj : objList)
    {
        obj.Render(screenBuf);
    }

    // ȭ�� ��ü�� ���
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
    // Start �Լ� ����
}

void Component::Update()
{
    // Update �Լ� ����
}

void print_title_screen()
{
    std::cout << "****************************************" << std::endl;
    std::cout << "*                                      *" << std::endl;
    std::cout << "*                                      *" << std::endl;
    std::cout << "*             ������ ����              *" << std::endl;
    std::cout << "*            (Snake Bite)              *" << std::endl;
    std::cout << "*                                      *" << std::endl;
    std::cout << "*            1. ���� ����              *" << std::endl;
    std::cout << "*            2. ���� ����              *" << std::endl;
    std::cout << "*            3. ���� ��ŷ ����         *" << std::endl;
    std::cout << "*            4. ���� ���� (esc)        *" << std::endl;
    std::cout << "*                                      *" << std::endl;
    std::cout << "****************************************" << std::endl;
}
int introduction_screen()
{
	std::cout << ANSI_COLOR_RESET"******************************************" << std::endl;
	std::cout << ANSI_COLOR_RESET"*         ���� ����ȭ���Դϴ�.           *" << std::endl;
	std::cout << ANSI_COLOR_RESET"*         ���� ������ ���Ұ̴ϴ�.        *" << std::endl;
	std::cout << ANSI_COLOR_RESET"******************************************" << std::endl;
	std::cout << ANSI_COLOR_RESET"*   Ÿ��Ʋȭ������ ���ư����? (Y/N)     *" << std::endl;
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
	std::cout << "���� ȭ���� ���� ���̸� �Է��ϼ���: ";
	std::cin >> width;
	std::cout << "���� ȭ���� ���� ���̸� �Է��ϼ���: ";
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
	std::cout << "�ȳ� �� ����(�����)" << std::endl;
}


int main()
{
	int game_state = 0; //���� ��������
	int isgamerunning = 1; //���� ����
	int mod_r = 1; //�ƹ� Ű�� �Է� ���� ���ϰ� �ϴ� �ڵ�
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
				// scene�� screenBuf�� Ÿ��Ʋ ȭ�� ����
			}

			key_input = _getch();

			mod_r = 0;

			switch (key_input)
			{
			case '1':
				start_game();
				break;
			case '2':
				std::cout << "�� ������ ������ �㼼���鼭 ������ִ� ������ �׾���Դϴ�." << std::endl;
				main();
				break;
			case '3':
				std::cout << "���� ������Ʈ����" << std::endl;
				main();
				break;
			case '4':
				if (key_input == '4')
				{
					isYesSelected = true;
					mod_r = 0; //�ƹ� Ű�� �Է� ���� ���ϰ� �ϴ� �ڵ�
					//���� ����
					Gotoxy(5, 100);
					std::cout << ANSI_COLOR_RESET "�����Ͻðڽ��ϱ�?" << std::endl;
					Gotoxy(5, 101);
					std::cout << ANSI_COLOR_YELLOW "[��]" << std::endl;
					Gotoxy(15, 101);
					std::cout << ANSI_COLOR_RESET "[�ƴϿ�]  " << std::endl;

					while (true) // ESC�� ������ ���� ������ �ݺ��Ѵ�.
					{
						if (_kbhit()) //Ű �Է� �ޱ�
						{
							char key = _getch();

							if (key == KEY_LEFT || key == KEY_RIGHT) // 'a' �Ǵ� 'd'�� �ԷµǸ� ���õ� �޴��� �����Ѵ�.
							{
								isYesSelected = !isYesSelected;

								// ���õ� �޴��� ���� ����� �Ǵ� �⺻ �������� ����Ѵ�.
								if (isYesSelected)
								{
									Gotoxy(5, 101);
									std::cout << ANSI_COLOR_YELLOW "[��]  ";
									Gotoxy(15, 101);
									std::cout << ANSI_COLOR_RESET "[�ƴϿ�]  ";
								}
								else
								{
									Gotoxy(5, 101);
									std::cout << ANSI_COLOR_RESET "[��]  ";
									Gotoxy(15, 101);
									std::cout << ANSI_COLOR_YELLOW "[�ƴϿ�]  ";
								}
							}
							else if (key == KEY_ENTER) // Enter�� �ԷµǸ� ���õ� �޴��� ���� �����ϰų� ������ ��� �����Ѵ�.
							{
								if (isYesSelected)
								{
									isgamerunning = false;
									break;
								}
								else
								{
									Gotoxy(5, 100);
									std::cout << "                     " << std::endl; //���� �޽��� �����
									Gotoxy(5, 101);
									std::cout << "     " << std::endl; //���� �޴� �����
									Gotoxy(15, 101);
									std::cout << "        " << std::endl;
									isgamerunning = true;
									break; //�ݺ��� ����
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
					mod_r = 0; //�ƹ� Ű�� �Է� ���� ���ϰ� �ϴ� �ڵ�
					//���� ����
					Gotoxy(5, 100);
					std::cout << ANSI_COLOR_RESET "�����Ͻðڽ��ϱ�?" << std::endl;
					Gotoxy(5, 101);
					std::cout << ANSI_COLOR_YELLOW "[��]" << std::endl;
					Gotoxy(15, 101);
					std::cout << ANSI_COLOR_RESET "[�ƴϿ�]  " << std::endl;

					while (true) // ESC�� ������ ���� ������ �ݺ��Ѵ�.
					{
						if (_kbhit()) //Ű �Է� �ޱ�
						{
							char key = _getch();

							if (key == KEY_LEFT || key == KEY_RIGHT) // 'a' �Ǵ� 'd'�� �ԷµǸ� ���õ� �޴��� �����Ѵ�.
							{
								isYesSelected = !isYesSelected;

								// ���õ� �޴��� ���� ����� �Ǵ� �⺻ �������� ����Ѵ�.
								if (isYesSelected)
								{
									Gotoxy(5, 101);
									std::cout << ANSI_COLOR_YELLOW "[��]  ";
									Gotoxy(15, 101);
									std::cout << ANSI_COLOR_RESET "[�ƴϿ�]  ";
								}
								else
								{
									Gotoxy(5, 101);
									std::cout << ANSI_COLOR_RESET "[��]  ";
									Gotoxy(15, 101);
									std::cout << ANSI_COLOR_YELLOW "[�ƴϿ�]  ";
								}
							}
							else if (key == KEY_ENTER) // Enter�� �ԷµǸ� ���õ� �޴��� ���� �����ϰų� ������ ��� �����Ѵ�.
							{
								if (isYesSelected)
								{
									isgamerunning = false;
									break;
								}
								else
								{
									Gotoxy(5, 100);
									std::cout << "                     " << std::endl; //���� �޽��� �����
									Gotoxy(5, 101);
									std::cout << "     " << std::endl; //���� �޴� �����
									Gotoxy(15, 101);
									std::cout << "        " << std::endl;
									isgamerunning = true;
									 //�ݺ��� ����
									std::cout << ANSI_COLOR_RESET "Ÿ��Ʋ�� ���ư��ϴ�.\n\n";
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
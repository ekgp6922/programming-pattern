#include <iostream> 
#include <conio.h> 
#include <Windows.h> 


int print_title_screen() {


    std::cout << "****************************************" << std::endl;
    std::cout << "*                                      *" << std::endl;
    std::cout << "*                                      *" << std::endl;
    std::cout << "*             지렁이 게임              *" << std::endl;
    std::cout << "*            (Snake  Bite)             *" << std::endl;
    std::cout << "*                                      *" << std::endl;
    std::cout << "*  1. 게임 시작                        *" << std::endl;
    std::cout << "*  2. 게임 설명                        *" << std::endl;
    std::cout << "*  3. 게임 랭킹 보기                   *" << std::endl;
    std::cout << "*  4. 게임 종료 (esc)                  *" << std::endl;
    std::cout << "*                                      *" << std::endl;
    std::cout << "****************************************" << std::endl;

    return 0;

}

void gotoxy(int x, int y) {

    COORD pos = { x,y };

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}


void print_game_screen(int width, int height) {
    char** map = (char**)malloc(sizeof(char*) * height);

    for (int i = 0; i < height; i++) {
        map[i] = (char*)malloc(sizeof(char) * width);

        for (int j = 0; j < width; j++) {
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1) {
                map[i][j] = 'o';
            }
            else {
                map[i][j] = ' ';
            }
        }
    }
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            std::cout << map[i][j] << " ";
        }
        std::cout << std::endl;
    }
    for (int i = 0; i < height; i++) {
        free(map[i]);
    }
    free(map);
}







int print_introduction_screen() {

    std::cout << "****************************************" << std::endl;
    std::cout << "*              게임 설명.              *" << std::endl;
    std::cout << "*      Snake bite란 뭘까욥?....        *" << std::endl;
    std::cout << "****************************************" << std::endl;
    std::cout << "*   타이틀화면으로 돌아갈까용? (Y/N)   *" << std::endl;

    return 0;
}


int main() {

    int game_state = 0;
    int mod = 1;
    int is_game_runing = 1;

    while (is_game_runing)
    {
        char key_input = 0;
        switch (game_state)
        {
        case 0:
            if (mod) {
                print_title_screen();
            };
            key_input = _getch();


            mod = 0;

            switch (key_input)
            {
            case '1':
                game_state = 1;
                mod = 1;
                break;
            case '2':
                game_state = 2;
                mod = 1;
                break;
            case '3':
                break;
            case '4':
                is_game_runing = 0;
                break;
            case 27:
                is_game_runing = 0;
            default:
                break;
            }
            break;
        case 1:

            if (mod) {
                int x = 0;
                int y = 0;
                std::cout << "*맵을 만들기 위해 x,y값을 입력해주세요!*" << std::endl;
                std::cout << "****************************************" << std::endl;
                scanf_s("%d", &x);
                x = x + 2;

                scanf_s("%d", &y);
                y = y + 2;

                system("cls");
                print_game_screen(x, y);
            };
            key_input = _getch();
            mod = 0;
            break;
        case 2:

            if (mod) {
                print_introduction_screen();
            }

            key_input = 0;
            key_input = _getch();

            mod = 0;

            if (key_input == 'y') {
                game_state = 0;
                mod = 1;
            }
            else if (key_input == 'n') {

            }

        default:
            break;
        }

    }
    return 0;
}

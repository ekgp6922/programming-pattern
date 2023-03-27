#include <iostream>
int main()
{	while(1)
	{
			std::cout<<"*";
			if(kbhit())
			{
					std::cout<<"snffla";
					if(getch()==27)
						break;
			}
	}
	return 0;
}

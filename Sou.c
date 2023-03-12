#include <stdio.h>
#include "ConsoleEngine.h"



char buf[30] = {
	0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0
};

int main()
{
	ENGINE_INIT(sizeof(char), 6, 5);

	//ENGINE_DrawRectFilled(0, 1, 3, 4, ' ', buf);


	//ENGINE_PutChar(6, 4, buf, '5');

	ENGINE_DrawLine(5, 4, 0, 0, buf, '2');

	while (1)
	{

		

		//EVENTS






		//DRAW
		ENGINE_SetCursorPos(0, 0);

		for (int y = 0; y < 5; y++)
		{
			for (int x = 0; x < 6; x++)
			{
				putchar(buf[x + y * 6] + 48);
			}
			putchar('\n');
		}

		

	}

	
}
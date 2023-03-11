#include <stdio.h>
#include "Header.h"



char buf[30] = {
	1, 1, 1, 1, 1, 1,
	1, 1, 2, 3, 2, 2,
	4, 4, 4, 2, 2, 2,
	4, 4, 4, 2, 2, 2,
	4, 4, 4, 2, 2, 2
};

int main()
{
	ENGINE_SetBufferSize(sizeof(char));
	ENGINE_SetDim(6, 5);
	
	ENGINE_PutChar(0, 1, buf, ' ');

	ENGINE_DrawRect(1, 1, 3, 4, ' '-48, buf);


	while (1)
	{

		printf("\033[H");

		for (size_t y = 0; y < 5; y++)
		{
			for (size_t x = 0; x < 6; x++)
			{
				putchar(buf[x + y * 6] + 48);
			}
			putchar('\n');
		}
		

	}

	
}
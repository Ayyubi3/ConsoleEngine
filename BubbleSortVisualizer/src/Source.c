#include "ConsoleEngine.h"
#include <stdio.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#define Sleep(x) usleep((x)*1000)
#endif



//These are the Inputs
#define BlockWidth 1
#define TargetArrayLength 40
int arr[TargetArrayLength] = { 13, 7, 18, 1, 4, 3, 17, 2, 12, 8, 6, 16, 19, 11, 0, 5, 10, 14, 15, 9, 0, 17, 1, 11, 12, 8, 6, 9, 18, 5, 7, 2, 19, 14, 16, 15, 3, 4, 13, 10 };
const int TimeInMilliseconds = 0;
//



#define Width (TargetArrayLength * BlockWidth + TargetArrayLength + 1)
#define Heigth (20)



char buf[Heigth][Width];


int main()
{
	ENGINE_INIT(sizeof(char), Width, Heigth);

	ENGINE_FILL(buf, ' ');

	ENGINE_DrawLine(2, Heigth - 1, Width - 1, Heigth - 1, buf, 205);
	ENGINE_PutChar(1, Heigth - 1, buf, 200);
	ENGINE_DrawLine(1, 0, 1, Heigth - 2, buf, 186);



	int Counter = 0;
	int cc = 0;


	while (1)
	{

		//Print Buffer
		ENGINE_SetCursorPos(0, 0);
		for (int y = 0; y < Heigth; y++)
		{
			for (int x = 0; x < Width; x++)
			{
				putchar(buf[y][x]);
			}
			putchar('\n');
		}


		//Clear Graph
		ENGINE_DrawRectFilled(2, 0, Width - 1, Heigth - 2, ' ', buf);


		int firstIndex = 2;
		for (size_t i = 0; i < TargetArrayLength; i++)
		{
			ENGINE_DrawRectFilled(firstIndex, Heigth - arr[i] - 1, firstIndex + BlockWidth - 1, Heigth - 2, '+', buf);
			firstIndex += BlockWidth + 1;


			ENGINE_SetCursorPos(0, 0);
			for (int y = 0; y < Heigth; y++)
			{
				for (int x = 0; x < Width; x++)
				{
					putchar(buf[y][x]);
				}
				putchar('\n');
			}
		}


		if (cc >= TargetArrayLength - 1)
			break;


		if (Counter != TargetArrayLength - 1)
		{

			if (arr[Counter] > arr[Counter + 1])
			{
				int temp = arr[Counter];
				arr[Counter] = arr[Counter + 1];
				arr[Counter + 1] = temp;
			}
			Counter++;

		}
		else if (Counter == TargetArrayLength - 1)
		{
			Counter = 0;
			cc++;
		}
		


		Sleep(TimeInMilliseconds);
	}
}
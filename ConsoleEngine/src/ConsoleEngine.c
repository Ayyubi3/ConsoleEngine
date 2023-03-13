#include <stdio.h>
#include <math.h>
#include "ConsoleEngine.h"

//IMPORTANT: Dont forget you assume in to be 4 bytes

static int BUFFERSIZE = 0;
static int X = 0;
static int Y = 0;

void ENGINE_INIT(unsigned int bufferTypeSize, int x, int y)
{
	BUFFERSIZE = bufferTypeSize;
	X = x;
	Y = y;
}

void ENGINE_PutChar(int x, int y, char* buf, char symb) 
{
	if (x < 0 || y < 0 || x >= X || y >= Y) 
		return;

	buf[y * X + x] = symb;
}



void ENGINE_FILL(char* buf, char sym)
{
	for (size_t i = 0; i < X*Y; i++)
	{
		buf[i] = sym;
	}
}



void ENGINE_DrawRectFilled(int LTx,int LTy,int RBx,int RBy, char symbol, char* buf)
{
	for (int y = LTy; y < RBy + 1; y++)
	{
		for (int x = LTx; x < RBx + 1; x++)
		{
			ENGINE_PutChar(x, y, buf, symbol);
			
		}
	}
}

void ENGINE_DrawRect(int LTx, int LTy, int RBx, int RBy, char symbol, char* buf)
{
	for (int y = LTy; y < RBy + 1; y++)
	{
		for (int x = LTx; x < RBx + 1; x++)
		{
			if (x == LTx || x == RBx || y == LTy || y == RBy)//with this line filled or not
			{
				ENGINE_PutChar(x, y, buf, symbol);

			}

		}
	}
}






void ENGINE_SetBackgroundColor(int R, int G, int B)
{
	printf("\x1b[48;2;%i;%i;%im", R, G, B);
}

void ENGINE_SetForegroundColor(int R, int G, int B)
{
	printf("\x1b[38;2;%i;%i;%im", R, G, B);
}

void ENGINE_SetCursorPos(int x, int y)
{
	printf("\033[%d;%dH", y, x);
}


void ENGINE_Clear()
{
	printf("\033[2J");
	printf("\033[H");
}






void ENGINE_DrawLine(int x0, int y0, int x1, int y1, char* buf, char syx)
{

	int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
	int dy = -abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
	int err = dx + dy, e2; /* error value e_xy */

	while (1) {
		ENGINE_PutChar(x0, y0, buf, syx);
		if (x0 == x1 && y0 == y1) break;
		e2 = 2 * err;
		if (e2 > dy) { err += dy; x0 += sx; } /* e_xy+e_x > 0 */
		if (e2 < dx) { err += dx; y0 += sy; } /* e_xy+e_y < 0 */
	}
}

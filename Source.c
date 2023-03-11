#include <stdio.h>
#include "Header.h"

//IMPORTANT: Dont forget you assume in to be 4 bytes

static int BUFFERSIZE = 0;
static int X = 0;
static int Y = 0;

void ENGINE_SetBufferSize(unsigned int bufferTypeSize)
{
	BUFFERSIZE = bufferTypeSize;
}
void ENGINE_SetDim(int x, int y)
{
	X = x;
	Y = y;
}

void ENGINE_PutChar(int x, int y, char* buf, char symb) 
{
	buf[y * X + x] = symb;
}


void ENGINE_DrawRect(int LTx,int LTy,int RBx,int RBy, char symbol, char* buf)
{
	for (size_t y = LTy; y < RBy + 1; y++)
	{
		for (size_t x = LTx; x < RBx + 1; x++)
		{
			ENGINE_PutChar(x, y, buf, symbol);
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
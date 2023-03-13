#pragma once


void ENGINE_INIT(unsigned int bufferTypeSize, int x, int y);

void ENGINE_PutChar(int x, int y, char* buf, char symb);

void ENGINE_DrawRect(int LTx, int LTy, int RBx, int RBy, char symbol, char* buf);
void ENGINE_DrawRectFilled(int LTx, int LTy, int RBx, int RBy, char symbol, char* buf);

void ENGINE_SetBackgroundColor(int R, int G, int B);
void ENGINE_SetForegroundColor(int R, int G, int B);
void ENGINE_SetCursorPos(int x, int y);


void ENGINE_Clear();
void ENGINE_FILL(char* buf, char sym);

void ENGINE_DrawLine(int x0, int y0, int x1, int y1, char* buf, char sy);

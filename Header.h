#pragma once


void ENGINE_SetBufferSize(unsigned int bufferTypeSize);
void ENGINE_SetDim(int x, int y);

void ENGINE_PutChar(int x, int y, char* buf, char symb);

void ENGINE_DrawRect(int LTx, int LTy, int RBx, int RBy, char symbol, char* buf);

void ENGINE_SetBackgroundColor(int R, int G, int B);
void ENGINE_SetForegroundColor(int R, int G, int B);
void ENGINE_SetCursorPos(int x, int y);
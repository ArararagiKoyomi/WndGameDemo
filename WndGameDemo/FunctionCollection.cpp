#include "FunctionCollection.h"
#include "ToolCollection.h"
#include <stdio.h>
#include <stdlib.h>

void DEMO::showTextInRandomPos(char* text, HWND hwnd, int width, int height)
{
	HDC hdc = GetDC(hwnd);
	SetTextColor(hdc, RGB(rand() % 256, rand() % 256, rand() % 256));

	// set the background color to black
	SetBkColor(hdc, RGB(0, 0, 0));

	// finally set the transparency mode to transparent
	SetBkMode(hdc, OPAQUE);

	// draw some text at a random location
	TextOut(hdc, rand() % width - 50, rand() % height - 20, text, strlen(text));
}


void DEMO::ansysButtomPress(HWND hwnd)
{
	char buffer[80];
	HDC hdc = GetDC(hwnd);

	/*
	for (short i = 0x00; i <= VK_SCROLL ; ++i)
	{
		sprintf(buffer, "Up Arrow: = %d   ", KEYDOWN(i));
		TextOut(hdc, 0, 0, buffer, strlen(buffer));
	}
	*/
	sprintf(buffer, "Up Arrow: = %d   ", KEYDOWN(VK_UP));
	TextOut(hdc, 0, 0, buffer, strlen(buffer));

	sprintf(buffer, "Down Arrow: = %d   ", KEYDOWN(VK_DOWN));
	TextOut(hdc, 0, 16, buffer, strlen(buffer));

	sprintf(buffer, "Right Arrow: = %d   ", KEYDOWN(VK_RIGHT));
	TextOut(hdc, 0, 32, buffer, strlen(buffer));

	sprintf(buffer, "Left Arrow: = %d   ", KEYDOWN(VK_LEFT));
	TextOut(hdc, 0, 48, buffer, strlen(buffer));

	sprintf(buffer, "Left Click: = %d   ", KEYDOWN(VK_LBUTTON));
	TextOut(hdc, 0, 64, buffer, strlen(buffer));

	sprintf(buffer, "Right Click: = %d   ", KEYDOWN(VK_RBUTTON));
	TextOut(hdc, 0, 80, buffer, strlen(buffer));

	sprintf(buffer, "Middle Click: = %d   ", KEYDOWN(VK_MBUTTON));
	TextOut(hdc, 0, 96, buffer, strlen(buffer));
	
	


	// release the dc back
	ReleaseDC(hwnd, hdc);
}
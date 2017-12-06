#include "DemoFunctionCollection.h"
#include "DemoToolCollection.h"
#include <string.h>

void DEMO::showTextInRandomPos(char* text, HWND hwnd)
{
	HDC hdc = GetDC(hwnd);
	SetTextColor(hdc, RGB(rand() % 256, rand() % 256, rand() % 256));

	// set the background color to black
	SetBkColor(hdc, RGB(0, 0, 0));

	// finally set the transparency mode to transparent
	SetBkMode(hdc, OPAQUE);

	// draw some text at a random location
	TextOut(hdc, rand() % 450 - 50, rand() % 420 - 20, text, strlen(text));

	Sleep(100);
}

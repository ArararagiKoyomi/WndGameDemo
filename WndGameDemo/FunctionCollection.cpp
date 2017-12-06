#include "FunctionCollection.h"
#include "ToolCollection.h"
#include <string.h>

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

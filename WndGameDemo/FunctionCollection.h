#ifndef WGD_FUNCTION_COLLECTION_H
#define WGD_FUNCTION_COLLECTION_H
#include "windows.h"


namespace DEMO
{
	void showTextInRandomPos(char* text, HWND hwnd, int width, int height);
	void ansysButtomPress(HWND hwnd);
}



#define KEYDOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)
#define KEYUP(vk_code)   ((GetAsyncKeyState(vk_code) & 0x8000) ? 0 : 1)

#endif


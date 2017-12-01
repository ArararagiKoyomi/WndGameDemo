#include "WndGameDemo.h"
#include "MessageBox.h"
#define WINDOW_CLASS_NAME "WND_GAME_DEMO"
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <windowsx.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevinstance, LPSTR lpCmdLine, int nCmdShow)
{
	WNDCLASSEX	winclass;	//winclass实例
	HWND		hwnd;		//消息处理函数
	MSG			msg;		//windowsill's
	
	winclass.cbSize	= sizeof(WNDCLASSEX);
	winclass.style = CS_DBLCLKS | CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
	winclass.lpfnWndProc = WindowProc;			//消息处理函数
	winclass.cbClsExtra = 0;					//额外向windows申请的内存，没什么卵用，忽略
	winclass.cbWndExtra = 0;					//额外向windows申请的内存，没什么卵用，忽略
	winclass.hInstance = hInstance;
	winclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	winclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	winclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	winclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	winclass.lpszMenuName = NULL;
	winclass.lpszClassName = TEXT(WINDOW_CLASS_NAME);
	
	//向windows注册winclass
	if (!RegisterClassEx(&winclass))
	{
		//注册失败
		TOOL::showMessageBox("Error!", "Theres somewhere wrong while registering winclass. Please check!");
		return 0;
	}

	//创建windows类的窗口
	char lpszClassName[] = "窗口";
	char lpszTitle[] = "测试窗口";
	if (!(hwnd = CreateWindowEx(
		NULL,
		LPCTSTR(lpszClassName),
		LPCTSTR(lpszTitle),
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		0,0,
		400,400,
		NULL,
		NULL,
		hInstance,
		NULL
		)))
	{
		//创建失败
		//TOOL::showMessageBox("Error!", "Theres somewhere wrong while creating windows handler. Please check!");
		//return 0;
	}
	//显示窗口
	ShowWindow(hwnd, nCmdShow);
	//绘制用户区
	UpdateWindow(hwnd);
	//主函数
	while (true)
	{
		//
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		//逻辑循环
		MainRoutine();
	}


	return 0;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;		//
	HDC			hdc;	//
	switch (msg)
	{
	case WM_CREATE:
	{
		//窗体创建时
		return 0;
	} break;
	case WM_PAINT:
	{
		//窗口改变时

	} break;
	case WM_DESTROY:
	{
		//窗体关闭时
		return 0;
	} break;
	default: break;
	}
	return DefWindowProc(hwnd, msg, wParam, lParam);
}

void MainRoutine()
{
	//todo
	return;
}

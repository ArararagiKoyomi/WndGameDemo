#include "WndGameDemo.h"
#include <windows.h>
#include <windowsx.h>
#include <stdio.h>     
#include <math.h>
#include "MessageBox.h"
#include "resource1.h"
#define WINDOW_CLASS_NAME "WND_GAME_DEMO"

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
	winclass.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));
	winclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	winclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	winclass.lpszMenuName = NULL;
	//winclass.lpszMenuName =	MAKEINTRESOURCE(IDR_MENU1);
	winclass.lpszClassName = TEXT(WINDOW_CLASS_NAME);
	winclass.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));
	
	//向windows注册winclass
	if (!RegisterClassEx(&winclass))
	{
		//注册失败
		TOOL::showMessageBox("Error!", "Theres somewhere wrong while registering winclass. Please check!");
		return 0;
	}

	//创建windows类的窗口
	char lpszClassName[] = "ClassName";
	char lpszTitle[] = "Title";
	if (!(hwnd = CreateWindowEx(
		NULL,
		TEXT(WINDOW_CLASS_NAME),
		TEXT(WINDOW_CLASS_NAME),
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		0, 0,
		400, 400,
		NULL,
		LoadMenu(hInstance, MAKEINTRESOURCE(IDR_MENU1)),
		hInstance,
		NULL
	)))
	{
		//创建失败
		TOOL::showMessageBox("Error!", "Theres somewhere wrong while creating windows handler. Please check!");
		return 0;
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
			if (msg.message == WM_QUIT)
			{
				break;
			}
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		//逻辑循环
		MainRoutine();
	}
	return(msg.wParam);
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
	case WM_COMMAND:
	{
		//处理菜单消息
		switch (LOWORD(wParam))
		{
		case ID_OPEN_FILE:
		{
			TOOL::showMessageBox("Open", "Correct!");
		} break;
		default:
			break;
		}
	} break;
	case WM_PAINT:
	{
		//窗口改变时
		hdc = BeginPaint(hwnd, &ps);
		EndPaint(hwnd, &ps);
	} break;
	case WM_DESTROY:
	{
		//窗体关闭时
		PostQuitMessage(0);
		return 0;
	} break;
	default: break;
	}
	return (DefWindowProc(hwnd, msg, wParam, lParam));
}

void MainRoutine()
{
	//todo
	return;
}

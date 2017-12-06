#include "WndGameDemo.h"
#include <windows.h>
#include <windowsx.h>
#include <mmsystem.h>  // very important and include WINMM.LIB too!
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "MessageBox.h"
#include "resource1.h"
#include "FunctionCollection.h"
#define WINDOW_CLASS_NAME "WND_GAME_DEMO"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevinstance, LPSTR lpCmdLine, int nCmdShow)
{
	//初始化窗口属性
	m_wndFrame = new DEMO::WndFrame(400, 400);

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
	winclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	winclass.lpszMenuName = NULL;
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
		m_wndFrame->getWidth(),
		m_wndFrame->getHeight(),
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
		MainRoutine(hwnd);
	}
	return(msg.wParam);
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_CREATE:
	{
		//窗体创建时
		WndInit();
		return 0;
	} break;
	case WM_SIZE:
	{
		int width = LOWORD(lParam);
		int height = HIWORD(lParam);
		m_wndFrame->upgradeSize(width, height);
	} break;
	case WM_COMMAND:
	{
		//处理菜单消息
		switch (LOWORD(wParam))
		{
		case ID_OPEN_LOG:
		{
			TOOL::showMessageBox("Open", "Correct!");
		} break;
		case ID_FILE_EXIT:
		{
			PostQuitMessage(0);
			return 0;
		} break;
		default:
			break;
		}
	} break;
	case WM_PAINT:
	{
		//窗口改变时
		PAINTSTRUCT ps;		//绘制结构
		HDC			hdc;	//设备界面句柄 handler to a device context
		RECT		rect;	//矩形区域结构
		//获取上下文句柄
		hdc = GetDC(hwnd); 
		//释放上下文环境，供其他函数使用
		ReleaseDC(hwnd, hdc);
		//获取窗口rect结构
		GetClientRect(hwnd, &rect);
		//处理完了消息队列中的WM_PAINT消息后，清除队列
		ValidateRect(hwnd, &rect);
		return 0;
	} break;
	case WM_DESTROY:
	{
		//窗体关闭时
		WinDestroy();
		PostQuitMessage(0);
		return 0;
	} break;
	default: break;
	}
	return (DefWindowProc(hwnd, msg, wParam, lParam));
}


void WndInit()
{
	
}

DEMO::WndFrame * getWndFrame()
{
	return m_wndFrame;
}

void WinDestroy()
{
	delete(m_wndFrame);
}

void MainRoutine(HWND hwnd)
{
	//todo
	//DEMO::showTextInRandomPos("PERO!", hwnd, m_wndFrame->getWidth(), m_wndFrame->getHeight());
	DEMO::ansysButtomPress(hwnd);


	//todo帧率控制
	//Sleep(100);
	return;
}

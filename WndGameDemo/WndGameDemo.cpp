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
	//��ʼ����������
	m_wndFrame = new DEMO::WndFrame(400, 400);

	WNDCLASSEX	winclass;	//winclassʵ��
	HWND		hwnd;		//��Ϣ������
	MSG			msg;		//windowsill's
	
	winclass.cbSize	= sizeof(WNDCLASSEX);
	winclass.style = CS_DBLCLKS | CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
	winclass.lpfnWndProc = WindowProc;			//��Ϣ������
	winclass.cbClsExtra = 0;					//������windows������ڴ棬ûʲô���ã�����
	winclass.cbWndExtra = 0;					//������windows������ڴ棬ûʲô���ã�����
	winclass.hInstance = hInstance;
	winclass.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));
	winclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	winclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	winclass.lpszMenuName = NULL;
	winclass.lpszClassName = TEXT(WINDOW_CLASS_NAME);
	winclass.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));
	
	//��windowsע��winclass
	if (!RegisterClassEx(&winclass))
	{
		//ע��ʧ��
		TOOL::showMessageBox("Error!", "Theres somewhere wrong while registering winclass. Please check!");
		return 0;
	}

	//����windows��Ĵ���
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
		//����ʧ��
		TOOL::showMessageBox("Error!", "Theres somewhere wrong while creating windows handler. Please check!");
		return 0;
	}
	//��ʾ����
	ShowWindow(hwnd, nCmdShow);
	//�����û���
	UpdateWindow(hwnd);
	//������
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
		//�߼�ѭ��
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
		//���崴��ʱ
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
		//����˵���Ϣ
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
		//���ڸı�ʱ
		PAINTSTRUCT ps;		//���ƽṹ
		HDC			hdc;	//�豸������ handler to a device context
		RECT		rect;	//��������ṹ
		//��ȡ�����ľ��
		hdc = GetDC(hwnd); 
		//�ͷ������Ļ���������������ʹ��
		ReleaseDC(hwnd, hdc);
		//��ȡ����rect�ṹ
		GetClientRect(hwnd, &rect);
		//����������Ϣ�����е�WM_PAINT��Ϣ���������
		ValidateRect(hwnd, &rect);
		return 0;
	} break;
	case WM_DESTROY:
	{
		//����ر�ʱ
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


	//todo֡�ʿ���
	//Sleep(100);
	return;
}

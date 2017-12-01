#include "WndGameDemo.h"
#include "MessageBox.h"
#define WINDOW_CLASS_NAME "WND_GAME_DEMO"
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <windowsx.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevinstance, LPSTR lpCmdLine, int nCmdShow)
{
	WNDCLASSEX	winclass;	//winclassʵ��
	HWND		hwnd;		//��Ϣ������
	MSG			msg;		//windowsill's
	
	winclass.cbSize	= sizeof(WNDCLASSEX);
	winclass.style = CS_DBLCLKS | CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
	winclass.lpfnWndProc = WindowProc;			//��Ϣ������
	winclass.cbClsExtra = 0;					//������windows������ڴ棬ûʲô���ã�����
	winclass.cbWndExtra = 0;					//������windows������ڴ棬ûʲô���ã�����
	winclass.hInstance = hInstance;
	winclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	winclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	winclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	winclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	winclass.lpszMenuName = NULL;
	winclass.lpszClassName = TEXT(WINDOW_CLASS_NAME);
	
	//��windowsע��winclass
	if (!RegisterClassEx(&winclass))
	{
		//ע��ʧ��
		TOOL::showMessageBox("Error!", "Theres somewhere wrong while registering winclass. Please check!");
		return 0;
	}

	//����windows��Ĵ���
	char lpszClassName[] = "����";
	char lpszTitle[] = "���Դ���";
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
		//����ʧ��
		//TOOL::showMessageBox("Error!", "Theres somewhere wrong while creating windows handler. Please check!");
		//return 0;
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
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		//�߼�ѭ��
		MainRoutine();
	}


	return 0;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{



	return LRESULT();
}

void MainRoutine()
{
	return;
}

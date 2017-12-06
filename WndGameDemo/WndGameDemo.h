#ifndef WGD_MAIN_H
#define WGD_MAIN_H
#include <windows.h>
#include <windowsx.h>
#include "WndFrame.h"

LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
void MainRoutine(HWND hwnd);
void WndInit();
void WinDestroy();
DEMO::WndFrame * getWndFrame();
DEMO::WndFrame *m_wndFrame;

#endif

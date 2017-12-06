#include "MessageBox.h"
#include <windows.h>
#include <windowsx.h>

void TOOL::showMessageBox(char * chTitle, char * chMessage)
{
	MessageBox(
		NULL,
		chMessage,
		chTitle,
		MB_OK | MB_ICONEXCLAMATION
	);
	return;
}

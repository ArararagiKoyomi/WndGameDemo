#include "DemoToolCollection.h"

LPCWSTR TOOL::getLPCWSTR(char * ch)
{
	const int len = strlen(ch);
	WCHAR wszClassName[256];
	memset(wszClassName, 0, sizeof(wszClassName));
	MultiByteToWideChar(
		CP_ACP,
		0,
		ch,
		strlen(ch) + 1,
		wszClassName,
		sizeof(wszClassName) / sizeof(wszClassName[0])
	);
	return wszClassName;
}

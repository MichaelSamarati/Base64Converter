#pragma once
#include <windows.h>

/*
1: Dark Blue
2: Dark Green
3: Light Blue
4: Dark Red
5: Purple
6: Orange
7: Light Gray
8: Gray
9: Blue
10: Bright Green
11: Cyan
12: Bright Red
13: Magenta
14: Yellow
15: White
*/

extern int CONSOLE_COLOR_INFO = 6;
extern int CONSOLE_COLOR_STATISTICS = 6;
extern int CONSOLE_COLOR_START = 2;
extern int CONSOLE_COLOR_STOP = 2;
extern int CONSOLE_COLOR_ERROR = 12;
extern int CONSOLE_COLOR_INPUT = 3;
extern int CONSOLE_COLOR_RESULT = 13;

void setConsoleColor(int n) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, n);
}

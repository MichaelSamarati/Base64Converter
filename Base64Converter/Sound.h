#pragma once
#include <windows.h>
#include <mmsystem.h>

#pragma comment(lib, "winmm.lib")

int playFinishSound() {
	PlaySound(TEXT("./sound/finished.wav"), NULL, SND_FILENAME | SND_ASYNC);
	return 0;
}

int playEndSound() {
	PlaySound(TEXT("./sound/sneeze.wav"), NULL, SND_FILENAME);
	return 0;
}
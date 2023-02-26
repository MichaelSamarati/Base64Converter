#pragma once
#include <chrono>
#include <thread>

uint64_t getMillisecondsTime() {
	using namespace std::chrono;
	uint64_t ms = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
	return ms;
}

void sleep(int ms) {
	std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

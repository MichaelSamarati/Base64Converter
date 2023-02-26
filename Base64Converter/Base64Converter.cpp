#include <iostream>
#include <string>
#include <stdlib.h> 
#include "Sound.h"
#include "Time.h"
#include "Converter.h"
#include "ConsoleColor.h"

int main() {
	setConsoleColor(CONSOLE_COLOR_START);
	std::cout << "Base64Converter started!\n";

	std::string options[3] = { "1", "2", "q" };
	std::string option;

	while (true) {
		try {
			setConsoleColor(CONSOLE_COLOR_INFO);
			std::cout << options[0] << ": Text => Base64\n";
			std::cout << options[1] << ": Base64 => Text\n";
			std::cout << options[2] << ": Quit\n";
			std::cout << "Choose an option...\n";

			setConsoleColor(CONSOLE_COLOR_INPUT);
			std::cin >> option;
			std::cout << "\n";

			if (option == options[0] || option == options[1]) { 
				std::string input;
				std::string result;
				setConsoleColor(CONSOLE_COLOR_INFO);
				std::cout << "Enter the string...\n";
				setConsoleColor(CONSOLE_COLOR_INPUT);
				std::cin.ignore();
				std::getline(std::cin, input);
				std::cout << "\n";
				std::cout << input;
				std::cout << "asd\n";
				auto startTime = getMillisecondsTime();
				if (option == options[0]) {
					result = textToBase64(input);
				}else if (option == options[1]) {
					result = base64ToText(input);
				}
				auto endTime = getMillisecondsTime();
				auto timeDifference = endTime - startTime;
				playFinishSound();

				setConsoleColor(CONSOLE_COLOR_STATISTICS);
				std::cout << "Converting took " << timeDifference << " ms\n";
				setConsoleColor(CONSOLE_COLOR_RESULT);
				std::cout << result << "\n\n\n";
			}
			else if (option == options[2]) {
				break;
			}
			else {
				continue;
			}
		}
		catch (...) {
			setConsoleColor(CONSOLE_COLOR_ERROR);
			std::cout << "Error occured!";
		}
	}

	setConsoleColor(CONSOLE_COLOR_STOP);
	std::cout << "Program stopped!\n";
	playEndSound();

	return 0;
}




#include "prompt.hpp"

#include <iostream>
#include <string>

// get integer within specified range from cin
int ask_int(const std::string& prompt, int min, int max) {

	int input;

	while (true) {
		std::cout << prompt;
		std::cin >> input;

		if (std::cin.fail()) {
			// handles invalid data type input
			std::cout << "Invalid input type.\n";

			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
		} else if (input > max || input < min) {
			// handles input outside interval [min, max]
			std::cout << "Outside input range.\n";

			std::cin.ignore(INT_MAX, '\n');
		} else {
			// returns valid input
			std::cin.ignore(INT_MAX, '\n');

			return input;
		}
	}
}

// asks the user to enter 'y' or 'n' and will keep asking until they give one of
// those responses 'y' returns true, 'n' returns false
bool ask_bool(const std::string& prompt, char yes, char no) {
	std::string input;

	while (true) {
		std::cout << prompt;
		std::getline(std::cin, input);

		if (input.size() == 1) {
			if (input[0] == yes) {
				return true;
			} else if (input[0] == no) {
				return false;
			}
		}

		std::cout << "Please enter \'y\' or \'n\' only.\n";
	}
}
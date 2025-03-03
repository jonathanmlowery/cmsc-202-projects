/*
 * Author: Jonathan Lowery
 * Course: CMSC-202
 * Assignment: Lab 2
 * Due Date: 02/21/2025
 * Description: This program allows a user to convert between feet and inches
 */

#include <iostream>
#include <limits>

void feet_to_inches(double* feet_ptr) { *feet_ptr *= 12; }
void inches_to_feet(double* inches_ptr) { *inches_ptr /= 12; }

// get integer within specified range from cin
int ask_int(std::string prompt,
            int min = std::numeric_limits<int>::min(),
            int max = std::numeric_limits<int>::max()) {

	int input;

	while (true) {
		std::cout << prompt;
		std::cin >> input;

		if (std::cin.fail()) {
			// handles invalid data type input
			std::cout << "Invalid input type.\n";

			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		} else if (input > max || input < min) {
			// handles input outside interval [min, max]
			std::cout << "Outside input range.\n";

			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		} else {
			// returns valid input
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			return input;
		}
	}
}

// get double within specified range from cin
double ask_double(std::string prompt,
                  double min = std::numeric_limits<double>::min(),
                  double max = std::numeric_limits<double>::max()) {

	double input;

	while (true) {
		std::cout << prompt;
		std::cin >> input;

		if (std::cin.fail()) {
			// handles invalid data type input
			std::cout << "Invalid input type.\n";

			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		} else if (input > max || input < min) {
			// handles input outside interval [min, max]
			std::cout << "Outside input range.\n";

			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		} else {
			// returns valid input
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			return input;
		}
	}
}

int main() {
	int mode;

	std::cout << "This program allows you to convert between feet and inches.\n";

	while (true) {
		std::cout << "Enter 1 to convert feet to inches.\n";
		std::cout << "Enter 2 to convert inches to feet.\n";
		std::cout << "Enter 3 to exit.\n";

		mode = ask_int("Enter 1, 2, or 3: ", 1, 3);

		if (mode == 1) {
			// convert feet to inches
			double distance = ask_double("Enter feet: ");
			std::cout << distance << "\n";
			feet_to_inches(&distance);

			// display inches
			std::cout << distance << " in.\n\n";
		} else if (mode == 2) {
			// convert inches to feet
			double distance = ask_double("Enter inches: ");
			inches_to_feet(&distance);

			// display feet
			std::cout << distance << " ft.\n\n";
		} else if (mode == 3) {
			// user input of 3 is sentinel value, exit application loop
			break;
		} else {
			// something must have slipped past input validation
			std::cerr << "Input validation error; mode = " << mode << "\n";

			return -1;
		}
	}

	return 0;
}
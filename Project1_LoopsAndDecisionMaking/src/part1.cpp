/*
 * Author: Jonathan Lowery
 * Course: CMSC-202
 * Assignment: Project 1
 * Due Date: 02/28/2025
 * Description: This program allows the user to generate a password
 */

#include <iostream>
#include <random>

const char* generate_password(std::uniform_int_distribution<char>&, std::mt19937&);
bool ask_yes_or_no();

int main(int, char**) {
	// create random number generator and seed it;
	std::random_device rd;
	std::mt19937 generator(rd());
	// create uniform char distribution for [A-Z] by casting ascii value ints to char
	std::uniform_int_distribution<char> distribution(65, 90);

	// program greeting
	std::cout << "This program will let you to generate a psuedo-random password.\n";
	std::cout << "Press enter to begin... ";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	bool is_user_satisfied = false;
	while (!is_user_satisfied) {
		const char* password = generate_password(distribution, generator);

		// display password and see if the user wants a different one
		std::cout << "Password: " << password << "\n";
		std::cout << "Is this password sufficient?\n";
		is_user_satisfied = ask_yes_or_no();
	}

	std::cout << "Goodbye!\n";

	return 0;
}

// creates a password from random capital letters in the format ABCD-EFGH-IJKL
const char* generate_password(std::uniform_int_distribution<char>& dist, std::mt19937& gen) {
	static char password[15] = {};

	// assign the char at each index to either a randomly generated [A-Z] or '-'
	// between each 4 letters
	for (int i = 0; i < 14; i++) {
		if ((i + 1) % 5 == 0) {
			password[i] = '-';
		} else {
			password[i] = dist(gen);
		}
	}

	return password;
}

// asks the user to enter 'y' or 'n' and will keep asking until they give one of
// those responses 'y' returns true, 'n' returns false
bool ask_yes_or_no() {
	std::string input;

	while (true) {
		std::cout << "Please enter \'y\' or \'n\' only: ";
		std::getline(std::cin, input);

		if (input.size() > 1) {
			// input is more than one character; have user try again
			continue;
		}

		switch (input[0]) {
			case 'y':
			case 'Y':
				return true;

			case 'n':
			case 'N':
				return false;
		}  // if input[0] isn't 'y', 'Y', 'n', or 'N', it loop over again
	}
}
/*
 * Author: Jonathan Lowery
 * Course: CMSC-202
 * Assignment: Lab 4
 * Due Date: 03/07/2025
 * Description: Simple program that encrypts user input with the caeser cipher
 */

#include <fstream>
#include <iostream>
#include <limits>
#include <string>

void write_to_file(std::string text, std::string file_name);
char shift_letter(char initial, int key);
int  ask_int(std::string prompt,
             int         min = std::numeric_limits<int>::min(),
             int         max = std::numeric_limits<int>::max());

int main(int argc, char **argv) {
	std::cout << "This program demonstrates the caeser cipher\n";
	std::cout << "Note: only encrypts letters, letter casing is unaffected.\n";
	std::cout << "Enter the text to be encrypted below.\n";

	std::string text;
	std::getline(std::cin, text);

	int key = ask_int("Enter a number between 1 and 25: ", 1, 25);

	// traverse input and encrypt each character
	for (int i = 0; i < text.size(); i++) {
		text[i] = shift_letter(text[i], key);
	}

	write_to_file(text, "secret_message.txt");
	std::cout << "Encrypted message saved in secret_message.txt\n";

	return 0;
}

void write_to_file(std::string text, std::string file_name) {
	std::ofstream output_stream(file_name);
	output_stream << text;
	output_stream.close();
}

// encrypts individual character using offset key
char shift_letter(char initial, int key) {
	bool is_uppercase;

	// A = 0, B = 1, ... Z = 25
	int alphabet_index;

	if (65 <= initial && initial <= 90) {
		// uppercase letters
		alphabet_index = initial - 65;
		is_uppercase   = true;
	} else if (97 <= initial && initial <= 122) {
		// lowercase letters
		alphabet_index = initial - 97;
		is_uppercase   = false;
	} else {
		// the char is not a letter; must be some other kind of character
		// caeser cipher won't apply, so we will return the char without change
		return initial;
	}

	int shifted_alphabet_index = (alphabet_index + key) % 26;

	// turn new index back into ascii char of the letter we want
	if (is_uppercase) {
		return shifted_alphabet_index + 65;
	} else {
		return shifted_alphabet_index + 97;
	}
}

// prompt user for integer with input validation
int ask_int(std::string prompt, int min, int max) {
	int input;

	while (true) {
		std::cout << prompt;
		std::cin >> input;

		if (std::cin.fail()) {
			// handles invalid data type input (or other stream errors)
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

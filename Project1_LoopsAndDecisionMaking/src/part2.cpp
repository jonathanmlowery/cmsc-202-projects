/*
 * Author: Jonathan Lowery
 * Course: CMSC-202
 * Assignment: Project 1
 * Due Date: 02/28/2025
 * Description: This program simulates account creation and authentication
 */

#include <iostream>

int main(int, char**) {
	std::cout << "This program will simulate account creation and login.\n";

	// account creation
	std::string username, password;

	std::cout << "Create a username: ";
	std::cin >> username;

	std::cout << "Create a password: ";
	std::cin >> password;

	// acount login
	int attempts_left = 3;
	while (attempts_left > 0) {
		std::cout << "\nWarning: " << attempts_left << " login attempts left.\n";

		std::string attempt_username, attempt_password;

		std::cout << "Username: ";
		std::cin >> attempt_username;

		std::cout << "Password: ";
		std::cin >> attempt_password;

		// check if username/password combo is correct
		if (attempt_username == username && attempt_password == password) {
			std::cout << "Login successful.\n";
			break;  // exit application loop upon successful login
		} else {
			std::cout << "Incorrect.\n";
			attempts_left--;
		}
	}

	if (attempts_left == 0) {
		std::cout << "Account locked.\n";
	}

	return 0;
}

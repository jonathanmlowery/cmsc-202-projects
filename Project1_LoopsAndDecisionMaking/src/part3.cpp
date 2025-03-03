/*
 * Author: Jonathan Lowery
 * Course: CMSC-202
 * Assignment: Project 1
 * Due Date: 02/28/2025
 * Description: This program simulates a best of 3 rock paper scissors match against a computer
 */

#include <iostream>
#include <random>

int get_winner(int, int);
int ask_int(int, int);
std::string stringify_choice(int);
std::string stringify_winner(int);
void update_scores(int&, int&, int);

int main(int, char**) {
	std::cout << "This program simulates a best of 3 rock paper scissors match against a computer.\n";
	int player_choice, computer_choice;
	int player_score = 0, computer_score = 0;

	// seed rand()
	std::srand(time(0));

	// simulate 3 rounds of rock paper scissors
	for (int i = 0; i < 3; i++) {
		std::cout << "Choose your move (1=rock, 2=paper, 3=scissors)\n";

		player_choice   = ask_int(1, 3);        // asks user to pick 1, 2, or 3
		computer_choice = std::rand() % 3 + 1;  // generates random int 1, 2, or 3
		int winner      = get_winner(player_choice, computer_choice);

		std::cout << "Player choice: " << stringify_choice(player_choice) << "\n";
		std::cout << "Computer choice: " << stringify_choice(computer_choice) << "\n";
		std::cout << "Winner: " << stringify_winner(winner) << "\n";

		update_scores(player_score, computer_score, winner);

		std::cout << "\n";
	}

	// calculate overall winner of the best of 3
	if (player_score > computer_score) {
		std::cout << "Player wins!\n";
	} else if (computer_score > player_score) {
		std::cout << "Computer wins!\n";
	} else {
		std::cout << "Tie!\n";
	}

	return 0;
}

// 0 = tie
// 1 = player wins
// 2 = computer wins
int get_winner(int player_choice, int computer_choice) {
	return (player_choice - computer_choice + 3) % 3;
}

// get integer within specified range from cin
int ask_int(int min, int max) {
	int input;

	while (true) {
		std::cout << "Enter an integer between " << min << " and " << max << ": ";
		std::cin >> input;

		if (std::cin.fail()) {
			// handles error due to invalid input type
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

std::string stringify_choice(int choice) {
	switch (choice) {
		case 1:
			return "rock";
		case 2:
			return "paper";
		case 3:
			return "scissors";
		default:
			return "unknown";
	}
}

std::string stringify_winner(int winner) {
	switch (winner) {
		case 0:
			return "tie";
		case 1:
			return "player";
		case 2:
			return "computer";
		default:
			return "unknown";
	}
}

// increase player/computer score counters based on the winner
void update_scores(int& player_score, int& computer_score, int winner) {
	if (winner == 0 || winner == 1) {
		player_score++;
	}
	if (winner == 0 || winner == 2) {
		computer_score++;
	}
}
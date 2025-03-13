#include "colors.hpp"

#include <iostream>
#include <sstream>
#include <string>

// display the number values for each color
void display_colors() {
	std::cout << "Here are the index values for each color.\n";

	for (int i = 0; i < COLOR_COUNT; i++) {
		std::cout << i << " -> " << COLORS[i] << "\n";
	}
}

// return hint after comparing the pegs to the user's guess
std::string get_hint(int (&pegs)[4], int (&guess_pegs)[4]) {
	std::string hint = "";

	// the indexes will correspond to the indexes of COLORS
	// the value at each index will be the count of occurances in real_pegs for
	// that color
	int color_occurances[6] = {};
	for (int color : pegs) {
		color_occurances[color]++;
	}

	// count Bs
	for (int i = 0; i < 4; i++) {
		bool char_matches = guess_pegs[i] == pegs[i];

		if (char_matches) {
			hint += 'B';

			color_occurances[guess_pegs[i]] -= char_matches;
		}
	}

	// count Ws
	for (int i = 0; i < 4; i++) {
		bool char_exists  = color_occurances[guess_pegs[i]] > 0;
		bool char_matches = guess_pegs[i] == pegs[i];

		if (!char_matches && char_exists) {
			hint += 'W';

			color_occurances[guess_pegs[i]] -= !char_matches && char_exists;
		}
	}

	return hint;
}

// returns string with all peg colors
std::string stringify_pegs(int (&pegs)[4]) {
	std::stringstream pegs_stream;

	for (int i = 0; i < 4; i++) {
		pegs_stream << COLORS[pegs[i]] << " ";
	}

	return pegs_stream.str();
}
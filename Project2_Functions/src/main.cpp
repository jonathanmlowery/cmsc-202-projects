/*
 * Author: Jonathan Lowery
 * Course: CMSC-202
 * Assignment: Project 2
 * Due Date: 03/14/2025
 * Description: The Mastermind board game, in your terminal
 */

#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <string>

#include "colors.hpp"
#include "prompt.hpp"

int main() {
    std::srand(std::time(0));

    std::cout << "Welcome to mastermind.\nIn this game, you will try to guess "
                 "the colors of 4 pegs.\nYou will be given hints about how "
                 "close your guesses are.\n";

    // start application loop
    // one iteration for each game of master mind
    while (true) {
        // set random colors for each peg
        int pegs [4];
        for (int i = 0; i < 4; i++) { pegs [i] = std::rand() % COLOR_COUNT; }

        char hint [5] = {};

        int guess_count;
        for (guess_count = 0; guess_count < GUESS_LIMIT; guess_count++) {
            display_colors();

            // ask user for a color for each peg
            int guess_pegs [4];
            for (int peg_index = 0; peg_index < 4; peg_index++) {
                std::string prompt = "Enter Peg "
                                   + std::to_string(peg_index + 1)
                                   + " Guess (enter an integer [0-5]): ";

                guess_pegs [peg_index] = ask_int(prompt, 0, 5);
            }

            std::cout << "You guessed: " << stringify_pegs(guess_pegs) << '\n';
            std::cout << "Hint: " << get_hint(pegs, guess_pegs) << "\n\n";

            // exit loop if pegs = guess_pegs since that defines a user win
            if (std::memcmp(pegs, guess_pegs, sizeof(pegs)) == 0) { break; }
        }

        if (guess_count == GUESS_LIMIT) {
            std::cout << "You lose!\n";
        } else {
            std::cout << "You won!\n";
        }

        std::cout << "Solution: " << stringify_pegs(pegs) << '\n';

        // exit loop if user doesn't wish to play another game
        if (!ask_bool("Play again? (y/n): ")) { break; }
    }

    return 0;
}
#ifndef COLORS_HPP
#define COLORS_HPP

#include <string>

const int COLOR_COUNT = 6;
const int GUESS_LIMIT = 10;

const char* const COLORS[] = {
    "white",
    "green",
    "orange",
    "purple",
    "pink",
    "yellow",
};

void display_colors();

std::string get_hint(int (&pegs)[4], int (&guess_pegs)[4]);
std::string stringify_pegs(int (&pegs)[4]);


#endif
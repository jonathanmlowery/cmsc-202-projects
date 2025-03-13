#ifndef PROMPT_HPP
#define PROMPT_HPP

#include <limits>
#include <string>

constexpr int INT_MIN = std::numeric_limits<int>::min();
constexpr int INT_MAX = std::numeric_limits<int>::max();

int  ask_int(const std::string& prompt, int min = INT_MIN, int max = INT_MAX);
bool ask_bool(const std::string& prompt, char yes = 'y', char no = 'n');

#endif
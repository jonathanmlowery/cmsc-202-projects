/* 
 * Author: Jonathan Lowery
 * Course: CMSC-202
 * Assignment: Lab 1
 */

#include <iostream>
#include <string>
#include <iomanip>

int main(int argc, char** argv) {
	// cout configuration to print floating point types with exactly 2 decimal places
	std::cout << std::fixed;
    std::cout << std::setprecision(2);
	
	std::string name;
	int total = 0;
	int count = 0;

	// print initial greeting and ask user for their name
	std::cout << "What is your name? ";
	std::cin >> name;
	std::cout << "Welcome to Lab 1, " << name << "!\n";
	std::cout << "This lab will calculate your final score by averaging your assignment scores.\n";
	std::cout << "Once you have added all assignment scores, enter a score of -1 to calculate final grade.\n";

	// infinite loop that can be broken out of by entering a score of -1
	while(1) {
		double score;
		std::cout << "Enter assignment score: ";
		std::cin >> score;
		
		// basic input validation
		if(std::cin.fail() || score > 100 || score < -1) {
			// clears cin error in case it failed and asks for a score again
			std::cout << "Invalid input. Please provide a valid number between 0 and 100, or -1 if you are done entering.\n";
			std::cin.clear();
      		std::cin.ignore(10000,'\n');
			continue;
		}
		
		if(score == -1) break; // exit loop when user wants to calculate final grade

		// if we make it this far in the loop iteration, that means we have a valid assignment score to add
		total += score;
		count++;
	}

	// if the user didn't enter any assignments, there's nothing to calculate
	if(count <= 0) {
		std::cout << "You didn't complete any assignments. You should be ashamed of yourself.\n";
		return -1;
	}

	// calculate numeric and letter grades
	double numeric_avg = (double) total / count;
	if(numeric_avg < 60) {        // F
		std::cout << name << ", you scored " << numeric_avg << "% which is a F.\n";
	} else if(numeric_avg < 70) { // D
		std::cout << name << ", you scored " << numeric_avg << "% which is a D.\n";
	} else if(numeric_avg < 80) { // C
		std::cout << "Okay Job, " << name << " you scored " << numeric_avg << "% which is a C.\n";
	} else if(numeric_avg < 90) { // B
		std::cout << "Good Job, " << name << " you scored " << numeric_avg << "% which is a B.\n";
	} else {                      // A
		std::cout << "Great Job, " << name << " you scored " << numeric_avg << "% which is an A.\n";
	}

	return 0;
}

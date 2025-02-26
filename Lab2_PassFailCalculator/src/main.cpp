/*
 * Author: Jonathan Lowery
 * Course: CMSC-202
 * Assignment: Lab 2
 * Due Date: 02/21/2025
 * Description: This program will determine if a user passed their classed based on their individual assignment scores.
 */

#include <iostream>
#include <string>
#include <memory>
#include <limits>
#include <iomanip>

// returns the average value of the scores in the grades array
// note: potentially unsafe if size param != actual size of array
// possible todo: switch to std::vector to ensure 
double calculate_average(double* grades, int size) {
    double total = 0;
    for(int i = 0; i < size; i++) {
        total += grades[i];
    }

    return total / size;
}

// returns string to send the user detailing whether they passed (average of 60 or higher)
std::string pass_message(double average_grade) {
    return average_grade >= 60
        ? "You passed the course.\n"
        : "You did not pass the course.\n";
}

int main(int argc, char** argv){
    // std::cout configuration to print floating point types with exactly 2 decimal places
	std::cout << std::fixed << std::setprecision(2);

    int assignment_count = 0;

    // user greeting and program explanation
    std::cout << "Welcome to Lab 2.\nThis program will tell you whether or not you have passed your class based on your assignment scores.\n\n";

    // prompt user for total # of assignments
    std::cout << "How many assignments did you have? ";
    std::cin >> assignment_count;

    // allocate heap memory for a double array since size isn't known at compile-time
    std::unique_ptr<double[]> grades = std::make_unique<double[]>(assignment_count);

    // prompt user for assignment scores for the number of assignments they stated
    for(int i = 0; i < assignment_count; i++) {
        std::cout << "Enter assignment #" << (i + 1) << ": ";
        double input;
        std::cin >> input;

        // input validation
        if(std::cin.fail() || input > 100 || input < 0) {
			// clears cin error in case it failed and asks for a score again
			std::cout << "Invalid input. Please provide a valid number between 0 and 100.\n";
			std::cin.clear();
      		std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            
            i--; // decrement because the for loop will automatically increment with continue, so this way i will stay the same
			continue;
		}

        grades[i] = input;
    }

    double average = calculate_average(grades.get(), assignment_count);
    std::cout << "Your average score was: " << average << "%\n";
    std::cout << pass_message(average);

    return 0;
}
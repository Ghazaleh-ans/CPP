#include "Bureaucrat.hpp"

int main() {
	std::cout << "=== Test 1: Valid bureaucrats ===" << std::endl;
	try {
		Bureaucrat bob("Bob", 50);
		std::cout << bob << std::endl;
		
		Bureaucrat alice("Alice", 1);
		std::cout << alice << std::endl;
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 2: Grade too high ===" << std::endl;
	try {
		Bureaucrat invalid("Invalid", 0); // Should throw
	} catch (std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 3: Grade too low ===" << std::endl;
	try {
		Bureaucrat invalid("Invalid", 151); // Should throw
	} catch (std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 4: Increment/Decrement ===" << std::endl;
	try {
		Bureaucrat charlie("Charlie", 2);
		std::cout << charlie << std::endl;
		
		charlie.incrementGrade(); // 2 -> 1
		std::cout << "After increment: " << charlie << std::endl;
		
		charlie.incrementGrade(); // Should throw (can't go below 1)
	} catch (std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 5: Decrement ===" << std::endl;
	try {
		Bureaucrat dave("Dave", 149);
		std::cout << dave << std::endl;
		
		dave.decrementGrade(); // 149 -> 150
		std::cout << "After decrement: " << dave << std::endl;
		
		dave.decrementGrade(); // Should throw (can't go above 150)
	} catch (std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}
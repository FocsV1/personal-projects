// Simple Palindrome Checker
#include <iostream>
#include <string>
#include <algorithm>

int main() {
	std::string input, processed;
	std::cout << "Enter a word or phrase: ";
	std::getline(std::cin, input);

	// Remove spaces and convert to lowercase
	for (char c : input) {
		if (!isspace(c)) {
			processed += std::tolower(c);
		}
	}

	std::string reversed = processed;
	std::reverse(reversed.begin(), reversed.end());

	if (processed == reversed) {
		std::cout << "It is a palindrome!" << std::endl;
	} else {
		std::cout << "It is not a palindrome." << std::endl;
	}
	return 0;
}

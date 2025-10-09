
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
	srand(time(0));
	int number = rand() % 100 + 1;
	int guess;
	int tries = 0;

	std::cout << "Welcome to Guess the Number!" << std::endl;
	std::cout << "Guess a number between 1 and 100" << std::endl;

	while (true)
	{
		std::cout << "Enter your guess: ";
		std::cin >> guess;
		tries = tries + 1;
		if (guess < number)
		{
			std::cout << "Too low!" << std::endl;
		}
		else if (guess > number)
		{
			std::cout << "Too high!" << std::endl;
		}
		else
		{
			std::cout << "You got it! It took you " << tries << " tries." << std::endl;
			break;
		}
	}
	return 0;
}

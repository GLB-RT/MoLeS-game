// MoreLessGame.cpp : Defines the entry point for the application.

#include <iostream>
#include <cstdlib>
#include <windows.h>

using namespace std;

int main()
{
	int lowerRange{}, upperRange{}, randomNumber{}, guessTry{};
	[[maybe_unused]] int numberTries{}; // Placeholder for the random number

	cout << "MORE OR LESS GAME" << "\n" << "Type lower range of numbers you want me to generate: ";
	cin >> lowerRange;
	cout << "\nType upper range of numbers you want me to generate: ";
	cin >> upperRange;

	if (upperRange <= lowerRange) {
		cout << "Invalid range. Upper range must be greater than lower\n" << "Stoopid, press any key to continue\n";
		cin.ignore();
		return 0; //Exit
	}
	else
	{
		randomNumber = rand() % upperRange + lowerRange;
		cout << "So I will think about number between " << lowerRange << " and " << upperRange << "\n\n" << "Try guess about what number I think by entering number: ";
	}

	while (true)
	{
		cin >> guessTry;
		if (guessTry == randomNumber)
		{
			cout << "Congratulation! You guessed it! The number I thought was: " << randomNumber << "\n" << "Press any key to exit\n";
			cin.ignore();
			return 0; // Exit
		}
		else if (guessTry < randomNumber)
		{
			cout << "HIGHER! Try again:";
		}
		else if (guessTry > randomNumber)
		{
			cout << "LOWER! Try again:";
		}
		else
		{
			cout << "Invalid input. Please enter a number between " << lowerRange << " and " << upperRange << ".\n";
		}
	}

	return 0;
}



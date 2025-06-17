// MoreLessGame.cpp : Defines the entry point for the application.

#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <random>

using namespace std;

int main()
{
    // Declare variables for the lower and upper range, the random number, and the user's guess
    int lowerRange{}, upperRange{}, randomNumber{}, guessTry{};
    [[maybe_unused]] int numberTries{}; // Placeholder for the random number (currently unused)

    // Prompt user for the lower range
    cout << "MORE OR LESS GAME" << "\n" << "Type lower range of numbers you want me to generate: ";
    cin >> lowerRange;
    // Prompt user for the upper range
    cout << "\nType upper range of numbers you want me to generate: ";
    cin >> upperRange;

    // Validate that the upper range is greater than the lower range
    if (upperRange <= lowerRange) {
        cout << "Invalid range. Upper range must be greater than lower\n" << "Stoopid, press any key to continue\n";
        cin.ignore();
        return 0; // Exit if invalid range
    }
    else
    {
        // Generate a random number within the specified range
		// Code generates always around 1. Left for a later improvement
        std::random_device dev; // Initialize random device
        std::mt19937 rng(dev()); // Seed the random number generator with a random device   
        std::uniform_int_distribution<std::mt19937::result_type> dist6(lowerRange, upperRange); // distribution in range [lowerRange, upperRange] 
        randomNumber = dist6(rng);
        std::cout << "So I will think about number between " << lowerRange << " and " << upperRange << "\n\n" << "Try guess about what number I think by entering number: ";
    }

    // Main game loop: keep asking the user to guess until they get it right
    while (true)
    {
        cin >> guessTry;
        if (guessTry == randomNumber)
        {
            // User guessed correctly
            cout << "Congratulation! You guessed it! The number I thought was: " << randomNumber << "\n" << "Press any key to exit\n";
            cin.ignore();
            return 0; // Exit
        }
        else if (guessTry < randomNumber)
        {
            // User's guess is too low
            cout << "HIGHER! Try again:";
        }
        else if (guessTry > randomNumber)
        {
            // User's guess is too high
            cout << "LOWER! Try again:";
        }
        else
        {
            // Invalid input (should not be reached with integer input)
            cout << "Invalid input. Please enter a number between " << lowerRange << " and " << upperRange << ".\n";
        }
    }

    return 0;
}

#include <iostream>
#include <cstdlib> // Needed for srand ()
#include <ctime> // Needed for time (0)


int main() {
    srand(std::time(0)); // Generates a new random number, using time as a seed.
beginning: // Will begin from here when a new random number is needed.
    int times{ 1 }; // Guess counter variable that increments every time the user guesses a number.
    int random = rand(); // "random" is a fixed random number taken from srand above.
    int guess; // The guessed number

    std::cout << "Try to guess the number I have thought. Please enter a number:\n";
question: // Will go back here when the guessed number is wrong.
    std::cin >> guess;

    if (guess == random) {
        char yn;
        std::cout << "That's correct! You won! It took you " << times << " guess(es). Do you want to play again (Y/N) ? \n";
        std::cin >> yn;
        yn = toupper(yn); // Makes yn case insensitive.
        if (yn == 'Y') {
            goto beginning;
        }

    }


    else {
        times++;

        if (guess < random) {
            std::cout << "Nope, try a higher number!\n";
            goto question;
        }
        else {
            std::cout << "Nope, try a lower number!\n";
            goto question;
        }
    }

    return 0;
}

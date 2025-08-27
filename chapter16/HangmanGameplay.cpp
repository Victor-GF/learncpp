#include "Hangman.h"
#include <iostream>
#include <limits>

void printStatus()
{
    // Print Word
    std::cout << "The word: ";

    for (const auto c : Hangman::Session::getRandomWord())
    {
        if (Hangman::Session::isLetterGuessed(c))
            std::cout << c;
        else
            std::cout << '_';
    }

    std::cout << '\t';

    // Print wrong guesses
    std::cout << "Wrong guesses: ";

    for (int i{Hangman::Session::MAX_WRONG_ATTEMPTS - 1}; i >= 0; --i)
    {
        std::cout << Hangman::Session::getWrongLetterGuesses()[i];
    }

    std::cout << '\n';
}

char inputForGuess()
{
    while (true)
    {
        std::cout << "Enter your next letter: ";

        char c{};
        std::cin >> c;

        // If user did something bad, try again
        if (!std::cin)
        {
            // Fix it
            std::cin.clear();
            std::cout << "That wasn't a valid input.  Try again.\n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        // Clear out any extraneous input
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        // If the user entered an invalid char, try again
        if (c < 'a' || c > 'z')
        {
            std::cout << "That wasn't a valid input.  Try again.\n";
            continue;
        }

        return c;
    }
}

void checkGuess(const char guess)
{
    // If the letter was already guessed, try again
    if (Hangman::Session::isLetterGuessed(guess))
    {
        std::cout << "You already guessed that. Try again.\n";
        return;
    }

    // Check if it is wrong guess
    bool wrongGuess{true};
    for (const auto c : Hangman::Session::getRandomWord())
    {
        if (c == guess)
        {
            wrongGuess = false;
            break;
        }
    }

    Hangman::Session::saveLetterGuessed(guess);

    if (wrongGuess)
    {
        Hangman::Session::addWrongLetterGuess(guess);
        std::cout << "No, '" << guess << "' is not in the word!\n";
    }
    else
    {
        std::cout << "Yes, '" << guess << "' is in the word!\n";
    }

    std::cout << '\n';
}

inline void checkEndgame()
{
    // Check game over
    {
        if (Hangman::Session::countWrongLetterGuesses() >= Hangman::Session::MAX_WRONG_ATTEMPTS)
        {
            std::cout << "You lost!  The word was: " << Hangman::Session::getRandomWord() << '\n';
            Hangman::endgame();
            return;
        }
    }

    // Check player wins
    {
        int rightGuessesCount{0};
        for (const auto c : Hangman::Session::getRandomWord())
        {
            if (Hangman::Session::isLetterGuessed(c))
                rightGuessesCount++;
        }

        if (rightGuessesCount >= Hangman::Session::getRandomWord().size())
        {
            std::cout << "You Win! Congratulations!\n";
            Hangman::endgame();
        }
    }
}

void Hangman::gameplay()
{
    printStatus();

    char guess{inputForGuess()};

    checkGuess(guess);

    checkEndgame();
}